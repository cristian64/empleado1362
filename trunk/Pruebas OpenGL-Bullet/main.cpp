#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include <iostream>
using namespace std;




////////////////////////////////////////////////////////////////////////
///                                                                  ///
///                      Variables globales                          ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////


int rotacionX = 0;
int rotacionY = 0;
int rotacionZ = 0;

float posicionX = 0;
float posicionY = 0;
float posicionZ = 0;

btDefaultCollisionConfiguration* collisionConfiguration;
btCollisionDispatcher* dispatcher;
btAxisSweep3* overlappingPairCache;
btSequentialImpulseConstraintSolver* solver;
btDiscreteDynamicsWorld* dynamicsWorld;
btCollisionShape* groundShape;
btAlignedObjectArray<btCollisionShape*> collisionShapes;
btRigidBody* body;



////////////////////////////////////////////////////////////////////////
///                                                                  ///
///                   Cabecera de las funciones                      ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////


void init();
void display();
void cubo(float tamano = 5);
void suelo();
void ejesCartesianos();
void manejador(unsigned char key, int x, int y);
void manejador2(int key, int x, int y);
void reshape(int width, int height);
int tiempoAnterior = glutGet(GLUT_ELAPSED_TIME);


////////////////////////////////////////////////////////////////////////
///                                                                  ///
///                            Principal                             ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
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
	groundShape = new btBoxShape(btVector3(btScalar(100.), btScalar(0.00001), btScalar(100.)));


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
	body->applyImpulse(btVector3(5, 15, 7), btVector3(4, 0, 3));

	dynamicsWorld->addRigidBody(body);







	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(650, 150);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Me cago en todo");
	init();
	glutIdleFunc(display);
	glutSpecialFunc(manejador2);
	glutKeyboardFunc(manejador);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}





////////////////////////////////////////////////////////////////////////
///                                                                  ///
///                    Definición de funciones                       ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLfloat luzAmbiente[]   = {0.65, 0.6, 0.6, 1.0};
	GLfloat luzDifusa[]     = {1, 1, 1, 1.0};
	GLfloat luzEspecular[]  = {11, 11, 11, 1.0};
	GLfloat luzExponente[]  = {64.0, 64.0, 64.0, 1.0};

	// Posición de la luz en coordenadas homogéneas,
	// soluciona el bug de exception error de OpenGL (x,y,z,w)
	GLfloat luzPosicion0[]  = {15.0,    250.0,  27.0, 1.0};
	/*GLfloat luzPosicion1[]  = {0.0, -5000.0,    0.0, 1.0};
	GLfloat luzPosicion2[]  = {0.0,    0.0, -5000.0, 1.0};*/


	glEnable (GL_POLYGON_SMOOTH);
	glEnable (GL_POLYGON_SMOOTH_HINT);
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_LINE_SMOOTH_HINT);
	glEnable (GL_POINT_SMOOTH);
	glEnable (GL_POINT_SMOOTH_HINT);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_DONT_CARE);

	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	//glEnable (GL_CULL_FACE);

	// Habilita Z-Buffer, Transparencias e Iluminación
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	// Habilita los materiales
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_AMBIENT, luzAmbiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, luzDifusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, luzEspecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, luzExponente);

	// Establece el foco de luz 0
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, luzPosicion0);

	reshape(500, 500);
}

void manejador(unsigned char key, int x, int y)
{
	// Salir del programa.
	if (key == 27)
	{
		exit(0);
	}

	if (key == 'W' || key == 'w') posicionZ++;
	if (key == 'S' || key == 's') posicionZ--;
	if (key == 'A' || key == 'a') posicionX++;
	if (key == 'D' || key == 'd') posicionX--;

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
		cout << "cambio gravedad" << endl;
	}
	if (key == 'R' || key == 'r')
	{
		btTransform trans;
		body->getMotionState()->getWorldTransform(trans);
		trans.setOrigin(btVector3(0,0,0));
		btMotionState* ms = body->getMotionState();
		ms->setWorldTransform(trans);
		body->setMotionState(ms);
		cout << "reset a 0,0,0" << endl;
	}
	if (key == 'M' || key == 'm')
	{
		body->applyCentralForce(btVector3(500, 0, 0));
		//body->setFriction(0);
		body->activate(true);
	}
}

void manejador2(int key, int x, int y)
{
	switch (key)
	{
		case 100:
			rotacionY -= 1;
			break;
		case 102:
			rotacionY += 1;
			break;
		case 101:
			rotacionX -= 1;
			break;
		case 103:
			rotacionX += 1;
			break;
	}
}

void display()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT); // Clear The Screen And The Depth Buffer
	glLoadIdentity(); // Reset The Projection Matrix

	glRotatef(rotacionX, 1, 0, 0); // Rotamos la cámara según las teclas del teclado.
	glRotatef(rotacionY, 0, 1, 0); // Rotamos la cámara según las teclas del teclado.
	glRotatef(rotacionZ, 0, 0, 1); // Rotamos la cámara según las teclas del teclado.
	glTranslatef(posicionX, posicionY, posicionZ); // Nos alejamos del centro de coordenadas.

	suelo();
	//ejesCartesianos();




	//########################################################################################################
	//###### Actualizamos el mundo diciendole que ha transcurrido una cantidad de tiempo.
	//########################################################################################################

	int tiempoActual = glutGet(GLUT_ELAPSED_TIME);
	dynamicsWorld->stepSimulation((tiempoActual - tiempoAnterior) / 1000.0, 10);
	tiempoAnterior = tiempoActual;



	//########################################################################################################
	//###### Extraemos la matriz de posicion del objeto y lo dibujamos (EL TAMAÑO DE OPENGL Y BULLET COINCIDE!!).
	//########################################################################################################
	if (body && body->getMotionState())
	{
		btTransform trans;
		body->getMotionState()->getWorldTransform(trans);
		GLfloat m[16];
		trans.getOpenGLMatrix(m);
		glMultMatrixf(m);
	}
	cubo();

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 0.1f, 50000.0f); // Calculate The Aspect Ratio Of The Window
	gluLookAt(-200, 100, -200, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void suelo()
{
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	float tamanoSuelo = 100.0f;
	glColor3f(200/255.0,190/255.0,99/255.0);
	glVertex3f(tamanoSuelo, 0.0f, tamanoSuelo);
	glColor3f(213/255.0,172/255.0,106/255.0);
	glVertex3f(tamanoSuelo, 0.0f, -tamanoSuelo);
	glColor3f(240/255.0,171/255.0,140/255.0);
	glVertex3f(-tamanoSuelo, 0.0f, -tamanoSuelo);
	glColor3f(190/255.0,160/255.0,95/255.0);
	glVertex3f(-tamanoSuelo, 0.0f, tamanoSuelo);
	glEnd();
}

void cubo(float tamano)
{
	glScalef(tamano, tamano, tamano);
	//glTranslatef(0, 1, 0);
	// draw a cube (6 quadrilaterals)
	glBegin(GL_QUADS); // start drawing the cube.

	// top of cube
	glNormal3f(0, 1, 0);
	glColor3f(0.0f, 1.0f, 0.0f); // Set The Color To Blue
	glVertex3f(1.0f, 1.0f, -1.0f); // Top Right Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, -1.0f); // Top Left Of The Quad (Top)
	glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom Left Of The Quad (Top)
	glVertex3f(1.0f, 1.0f, 1.0f); // Bottom Right Of The Quad (Top)

	// bottom of cube
	glNormal3f(0, -1, 0);
	glColor3f(1.0f, 0.5f, 0.0f); // Set The Color To Orange
	glVertex3f(1.0f, -1.0f, 1.0f); // Top Right Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, 1.0f); // Top Left Of The Quad (Bottom)
	glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (Bottom)
	glVertex3f(1.0f, -1.0f, -1.0f); // Bottom Right Of The Quad (Bottom)

	// front of cube
	glNormal3f(0, 0, 1);
	glColor3f(1.0f, 0.0f, 0.0f); // Set The Color To Red
	glVertex3f(1.0f, 1.0f, 1.0f); // Top Right Of The Quad (Front)
	glVertex3f(-1.0f, 1.0f, 1.0f); // Top Left Of The Quad (Front)
	glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom Left Of The Quad (Front)
	glVertex3f(1.0f, -1.0f, 1.0f); // Bottom Right Of The Quad (Front)

	// back of cube.
	glNormal3f(0, 0, -1);
	glColor3f(1.0f, 1.0f, 0.0f); // Set The Color To Yellow
	glVertex3f(1.0f, -1.0f, -1.0f); // Top Right Of The Quad (Back)
	glVertex3f(-1.0f, -1.0f, -1.0f); // Top Left Of The Quad (Back)
	glVertex3f(-1.0f, 1.0f, -1.0f); // Bottom Left Of The Quad (Back)
	glVertex3f(1.0f, 1.0f, -1.0f); // Bottom Right Of The Quad (Back)

	// left of cube
	glNormal3f(-1, 0, 0);
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex3f(-1.0f, 1.0f, 1.0f); // Top Right Of The Quad (Left)
	glVertex3f(-1.0f, 1.0f, -1.0f); // Top Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Left Of The Quad (Left)
	glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom Right Of The Quad (Left)

	// Right of cube
	glNormal3f(1, 0, 0);
	glColor3f(1.0f, 0.0f, 1.0f); // Set The Color To Violet
	glVertex3f(1.0f, 1.0f, -1.0f); // Top Right Of The Quad (Right)
	glVertex3f(1.0f, 1.0f, 1.0f); // Top Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, 1.0f); // Bottom Left Of The Quad (Right)
	glVertex3f(1.0f, -1.0f, -1.0f); // Bottom Right Of The Quad (Right)

	glEnd(); // Done Drawing The Cube
	//glTranslatef(0, -1, 0);
}

void ejesCartesianos()
{
	// Eje X. (rojo)
	glColor3f(1, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(1000, 0, 0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3f(-1000, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	// Eje Y. (verde)
	glColor3f(0, 1, 0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1000, 0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3f(0, -1000, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	// Eje Z. (azul)
	glColor3f(0, 0, 1);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1000);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -1000);
	glVertex3f(0, 0, 0);
	glEnd();
}
