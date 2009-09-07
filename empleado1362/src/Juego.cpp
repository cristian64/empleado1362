/// Fichero de definición de la clase Juego.
/** \file Juego.cpp
 */

#include "Juego.h"
#include <iostream>

using namespace std;

// Constructor por defecto.
Juego::Juego()
{
	// Obtenemos las interfaces.
	interfazGFX = InterfazGFX::getInstancia();
	interfazIA = InterfazIA::getInstancia();
	interfazPSX = InterfazPSX::getInstancia();
	interfazINF = InterfazINF::getInstancia();
	interfazSND = InterfazSND::getInstancia();

	niveles = NULL;
	done = 0;
}

// Destructor por defecto.
Juego::~Juego()
{
	delete interfazGFX;
	delete interfazIA;
	delete interfazPSX;
	delete interfazINF;
	delete interfazSND;
}

// Inicia el juego.
void Juego::iniciar()
{
	// Iniciamos las interfaces.
	interfazGFX->iniciar();
	interfazIA->iniciar();
	interfazPSX->iniciar();
	interfazINF->iniciar();
	interfazSND->iniciar();

	// Obtenemos los inputs devices.
	setInputDevices(interfazGFX->getmInputManager(), interfazGFX->getmMouse(), interfazGFX->getmKeyboard());

	done = 0;
	while(done == 0)
	{
		render();
		procesarTeclado();
		procesarRaton();
		actualizar();
		
	}
}

/// Actualiza el juego.
void Juego::actualizar()
{
	// Actualiza IA
	//interfazIA->actualizar();

	// Actualiza PSX
	//interfazPSX->actualizar();
	
	// Actualiza GFX
	/*
	list<Objetos> objetos = niveles.getPantalla(niveles.getPantallaActual().getX, niveles.getPantallaActual().getY()).getObjetos;
	list<Objetos>::iterator pos = objetos.begin();
	while(pos!=objetos.end())
	{
		Objeto objeto = *pos;
		if(objeto != NULL)
		{
			objeto.actualizar;
		}
		else
		{
			cout << "<Juego.cpp::actualizar> Error, el objeto no existe." << endl;
		}
		pos++;
	}
	*/
}

/// Realiza un render.
void Juego::render()
{
	interfazGFX->dibujar();
}

/// Procesa los eventos de teclado.
//bool Juego::procesarTeclado(const FrameEvent& evt)
bool Juego::procesarTeclado()
{
	if( mKeyboard->isKeyDown(OIS::KC_ESCAPE))
	{
		// Mostrar menú
		done = 1;

	}

	if(mKeyboard->isKeyDown(OIS::KC_UP) || mKeyboard->isKeyDown(OIS::KC_W) )
	{
		//Salto
		cout << "Salto" << endl;
	}

	if(mKeyboard->isKeyDown(OIS::KC_DOWN) || mKeyboard->isKeyDown(OIS::KC_S) )
	{
		// Agacharse
		cout << "Agacharse" << endl;
	}

	if(mKeyboard->isKeyDown(OIS::KC_RIGHT) || mKeyboard->isKeyDown(OIS::KC_D) )
	{
		// Desplazar derecha
		cout << "Derecha" << endl;
	}

	if(mKeyboard->isKeyDown(OIS::KC_LEFT) || mKeyboard->isKeyDown(OIS::KC_A) )
	{
		// Desplazar izquierda
		cout << "Izquierda" << endl;
	}

	return true;
}

/// Procesa los eventos del ratón.
//bool Juego::procesarRaton(const FrameEvent& evt)
bool Juego::procesarRaton()
{
	const OIS::MouseState &ms = mMouse->getMouseState();
	if( ms.buttonDown( OIS::MB_Right ) )
	{
		cout << "Botón derecho." << endl;
	}
	else if (ms.buttonDown (OIS::MB_Left ) )
	{
		cout << "Botón izquierdo." << endl;
	}
	else if (ms.buttonDown (OIS::MB_Middle ) )
	{
		cout << "Botón centro." << endl;
	}
	return true;
}

/// Obtiene el mInput Manager.
OIS::InputManager* Juego::getmInputManager() const
{
	return mInputManager;
}

/// Establece el mInput Manager.
void Juego::setmInputManager(OIS::InputManager* mInputManager)
{
	this->mInputManager = mInputManager;
}

/// Obtiene el mMouse.
OIS::Mouse* Juego::getmMouse() const
{
	return mMouse;
}

/// Establece el mMouse.
void Juego::setmMouse(OIS::Mouse* mMouse)
{
	this->mMouse = mMouse;
}

/// Obtiene el mKeyboard.
OIS::Keyboard* Juego::getmKeyboard() const
{
	return mKeyboard;
}

/// Establece el mKeyboard.
void Juego::setmKeyboard(OIS::Keyboard* mKeyboard)
{
	this->mKeyboard = mKeyboard;
}

/// Establece todos los Input devices.
void Juego::setInputDevices(OIS::InputManager* mInputManager, OIS::Mouse* mMouse, OIS::Keyboard* mKeyboard)
{
	setmInputManager(mInputManager);
	setmMouse(mMouse);
	setmKeyboard(mKeyboard);
}
