/// Fichero de definición de la clase InterfazPSX.
/** \file InterfazPSX.cpp
 */

#include "InterfazPSX.h"
#include <iostream>

using namespace std;

InterfazPSX* InterfazPSX::instancia = NULL;

// Constructor por defecto.
InterfazPSX::InterfazPSX()
{

}

// Destructor por defecto.
InterfazPSX::~InterfazPSX()
{
	// Liberamos la memoria.
}

// Devuelve la instancia de la clase singleton.
InterfazPSX* InterfazPSX::getInstancia()
{
	if(instancia == NULL)
		instancia = new InterfazPSX();
	return instancia;
}

// Inicia la interfaz.
void InterfazPSX::iniciar()
{
	//########################################################################################################
	//###### Se crea el mundo (y se le da un tamaño y una gravedad).
	//########################################################################################################

	///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	collisionConfiguration = new btDefaultCollisionConfiguration();

	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	dispatcher = new btCollisionDispatcher(collisionConfiguration);

	///the maximum size of the collision world. Make sure objects stay within these boundaries
	///Don't make the world AABB size too large, it will harm simulation quality and performance
	btVector3 worldAabbMin(-10000, -10000, -10000);
	btVector3 worldAabbMax(10000, 10000, 10000);
	int maxProxies = 1024;
	overlappingPairCache = new btAxisSweep3(worldAabbMin, worldAabbMax, maxProxies);

	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	solver = new btSequentialImpulseConstraintSolver;

	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

	dynamicsWorld->setGravity(btVector3(0, -100, 0));







	//########################################################################################################
	//###### Insertamos el suelo. Con masa 0 para que sea un objeto estático.
	//########################################################################################################

	/////////////////////////////////////////////////////////////////////
	//create a dynamic rigidbody
	/////////////////////////////////////////////////////////////////////

	///create a few basic rigid bodies
	groundShape = new btBoxShape(btVector3(btScalar(1000.), btScalar(43.00001), btScalar(1000.)));


	//keep track of the shapes, we release memory at exit.
	//make sure to re-use collision shapes among rigid bodies whenever possible!
	//btAlignedObjectArray<btCollisionShape*> collisionShapes;

	collisionShapes.push_back(groundShape);

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(0, 0, 0));

	btScalar mass(0.);

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		groundShape->calculateLocalInertia(mass, localInertia);

	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
	body = new btRigidBody(rbInfo);

	//add the body to the dynamics world
	dynamicsWorld->addRigidBody(body);








	//########################################################################################################
	//###### Insertamos un cubo con un impulso inicial y una posición inicial no estable (para que caiga).
	//########################################################################################################

	//create a dynamic rigidbody

	btCollisionShape* colShape = new btBoxShape(btVector3(5, 5, 5));
	//btCollisionShape* colShape = new btSphereShape(btScalar(1.));
	collisionShapes.push_back(colShape);

	/// Create Dynamic Objects
	btTransform startTransform;
	startTransform.setIdentity();


	mass = btScalar(1.f);

	//rigidbody is dynamic if and only if mass is non zero, otherwise static
	isDynamic = (mass != 0.f);

	localInertia = btVector3(0, 0, 0);
	if (isDynamic)
		colShape->calculateLocalInertia(mass, localInertia);

	startTransform.setOrigin(btVector3(2, 40, 0));
	btQuaternion rotacion(10, 220, 30, 40);
	startTransform.setRotation(rotacion);

	//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
	myMotionState = new btDefaultMotionState(startTransform);
	rbInfo = btRigidBody::btRigidBodyConstructionInfo(mass, myMotionState, colShape, localInertia);

	rbInfo.m_linearSleepingThreshold = 0;
	body = new btRigidBody(rbInfo);
	body->applyImpulse(btVector3(5, 10, 7), btVector3(4, 0, 3));

	dynamicsWorld->addRigidBody(body);




	
	//Algunas cosillas que se pueden hacer con el cuerpo "body", que sería el personaje principal para hacer las pruebas.
	/*
	if (key == 'P' || key == 'p')
	{
		body->applyImpulse(btVector3(0, 47, 0), btVector3(0, 0, 0));
		cout << "impulso!!" << endl;
	}
	if (key == 'G' || key == 'g')
	{
		body->applyImpulse(btVector3(1, 2, 1), btVector3(4, 7, 3));
		cout << "giro" << endl;
	}
	if (key == 'I' || key == 'i')
	{
		dynamicsWorld->setGravity(btVector3(100, -100, 10));
	}
	if (key == 'R' || key == 'r')
	{
		btTransform trans;
		body->getMotionState()->getWorldTransform(trans);
		trans.setOrigin(btVector3(0,0,0));
		body->getMotionState()->setWorldTransform(trans);
	}
	*/


	//########################################################################################################
	//###### Actualizamos el mundo diciendole que ha transcurrido una cantidad de tiempo.
	//###### Hay que hacerlo en cada render, diciéndoselo a Ogre de alguna forma
	//########################################################################################################
	/*
	int tiempoActual = glutGet(GLUT_ELAPSED_TIME);
	dynamicsWorld->stepSimulation((tiempoActual - tiempoAnterior) / 1000.0, 10);
	tiempoAnterior = tiempoActual;
	*/



	//########################################################################################################
	//###### Extraemos la matriz de posicion del objeto y se la asignamos al nodo de Ogre para la posición.
	//###### En OpenGL, lo que se hacía era multiplicar la matriz extraida en la ModelMatrix, con Ogre
	//###### Habrá que asignarle la posición al nodo, no sé cómo.
	//########################################################################################################
	/*
	if (body && body->getMotionState())
	{
		btTransform trans;
		body->getMotionState()->getWorldTransform(trans);
		GLfloat m[16];
		trans.getOpenGLMatrix(m);

		
		glMultMatrixf(m);
	}
	cubo();
	*/
}

// Actualiza la interfaz física.
void InterfazPSX::actualizar(int tiempoTranscurrido)
{
	dynamicsWorld->stepSimulation(tiempoTranscurrido / 1000.0, 10);
}

// Éste método habría que borrarlo. Es de prueba.
void InterfazPSX::moverPavico(string movimiento)
{
	if (movimiento == "arriba")
	{
		body->applyImpulse(btVector3(0, 50, 0), btVector3(0,0,0));
	}
	if (movimiento == "abajo")
	{
		body->applyImpulse(btVector3(0, -50, 0), btVector3(0,0,0));
	}
	if (movimiento == "derecha")
	{
		body->applyImpulse(btVector3(10, 0, 0), btVector3(0,0,0));
	}
	if (movimiento == "izquierda")
	{
		body->applyImpulse(btVector3(-10, 0, 0), btVector3(0,0,0));
	}
	if (movimiento == "dentro")
	{
		body->applyImpulse(btVector3(0, 0, -10), btVector3(0,0,0));
	}
	if (movimiento == "fuera")
	{
		body->applyImpulse(btVector3(0, 0, 10), btVector3(0,0,0));
	}
}
