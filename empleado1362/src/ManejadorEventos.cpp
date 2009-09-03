/// Fichero de definición de la clase ManejadorEventos.
/** \file ManejadorEventos.cpp
 */

#include "ManejadorEventos.h"
#include <iostream>

using namespace std;

// Constructor por defecto.
ManejadorEventos::ManejadorEventos()
{
	OIS::ParamList pl;
	//std::ostringstream windowHndStr;
	//pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
	mInputManager = OIS::InputManager::createInputSystem( pl );
	mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, false ));
	mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, false ));
}

// Destructor por defecto.
ManejadorEventos::~ManejadorEventos()
{
	mInputManager->destroyInputObject( mMouse );
	mInputManager->destroyInputObject( mKeyboard );

	OIS::InputManager::destroyInputSystem(mInputManager);
	mInputManager = NULL;
}

/// Procesa los eventos de teclado.
//bool ManejadorEventos::procesarTeclado(const FrameEvent& evt)
bool ManejadorEventos::procesarTeclado()
{
	if( mKeyboard->isKeyDown(OIS::KC_ESCAPE))
	{
		// Mostrar menú
	}
	
	if(mKeyboard->isKeyDown(OIS::KC_UP) || mKeyboard->isKeyDown(OIS::KC_W) )
	{
		//Salto
	}
	
	if(mKeyboard->isKeyDown(OIS::KC_DOWN) || mKeyboard->isKeyDown(OIS::KC_S) )
	{
		// Agacharse
	}
	
	if(mKeyboard->isKeyDown(OIS::KC_RIGHT) || mKeyboard->isKeyDown(OIS::KC_D) )
	{
		// Desplazar derecha
	}
	
	if(mKeyboard->isKeyDown(OIS::KC_LEFT) || mKeyboard->isKeyDown(OIS::KC_A) )
	{
		// Desplazar izquierda
	}
	
	return true;
}

/// Procesa los eventos del ratón.
//bool ManejadorEventos::procesarRaton(const FrameEvent& evt)
bool ManejadorEventos::procesarRaton()
{
	const OIS::MouseState &ms = mMouse->getMouseState();
	if( ms.buttonDown( OIS::MB_Right ) )
	{
		cout << "lol" << endl;
	}
	else
	{
		
	}

	return true;
}
