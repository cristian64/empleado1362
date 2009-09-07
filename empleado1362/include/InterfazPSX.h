/// Fichero de cabecera de la clase InterfazPSX.
/** \file InterfazPSX.h
 */

#ifndef _INTERFAZPSX_H
#define _INTERFAZPSX_H

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include <iostream>

using namespace std;


/** Interfáz física del juego que se ocupa de interactuar con PhysX.
*/
class InterfazPSX
{
    
    public:

        /// Obtiene la instancia.
        static InterfazPSX* getInstancia();

        /// Destructor por defecto.
        ~InterfazPSX();

        /// Inicia la interfaz.
        void iniciar();


    private:

        /// Constructor por defecto.
        InterfazPSX();

        /// Instancia de la clase.
        static InterfazPSX* instancia;

        btDefaultCollisionConfiguration* collisionConfiguration;
        btCollisionDispatcher* dispatcher;
        btAxisSweep3* overlappingPairCache;
        btSequentialImpulseConstraintSolver* solver;
        btDiscreteDynamicsWorld* dynamicsWorld;
        btCollisionShape* groundShape;
        btAlignedObjectArray<btCollisionShape*> collisionShapes;
        btRigidBody* body;


    protected:
	
};
		
#endif
