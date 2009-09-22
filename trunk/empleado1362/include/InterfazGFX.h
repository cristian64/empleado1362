/// Fichero de cabecera de la clase InterfazGFX.
/** \file InterfazGFX.h
 */
	
#ifndef _INTERFAZGFX_H
#define _INTERFAZGFX_H

#include "Ogre.h"
#include "OgreStringConverter.h"
#include "OgreException.h"
#include "OgreConfigFile.h"
#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>
#include <iostream>

using namespace std;
using namespace Ogre;


/** Interfáz gráfica del juego que se ocupa de interactuar con Ogre.
*/
class InterfazGFX: public FrameListener, public WindowEventListener
{
	public:

		/// Obtiene la instancia.
		static InterfazGFX* getInstancia();

		/// Destructor por defecto.
		~InterfazGFX();

		/// Inicia la interfaz.
		void iniciar();

                /// Actualiza la interfaz gráfica.
                void actualizar();



		/// Dibuja la escena.
		bool dibujar() const;
		
		/// Obtiene el mInput Manager.
		OIS::InputManager* getmInputManager() const;

		/// Establece el mInput Manager.
		void setmInputManager(OIS::InputManager* mInputManager);

		/// Obtiene el mMouse.
		OIS::Mouse* getmMouse() const;

		/// Establece el mMouse.
		void setmMouse(OIS::Mouse* mMouse);

		/// Obtiene el mKeyboard.
		OIS::Keyboard* getmKeyboard() const;

		/// Establece el mKeyboard.
		void setmKeyboard(OIS::Keyboard* mKeyboard);

		/// Establece todos los input devices.
		void setInputDevices(OIS::InputManager* mInputManager, OIS::Mouse* mMouse, OIS::Keyboard* mKeyboard);

	private:

		/// Constructor por defecto.
		InterfazGFX();

		/// Instancia de la clase.
		static InterfazGFX* instancia;

		/// Nodo raíz del árbol.
		Root *mRoot;

		/// Nodo de la cámara.
		Camera* mCamera;

		/// SceneManager.
		SceneManager* mSceneMgr;

		/// Ventana.
		RenderWindow* mWindow;

		/// Ruta de los recursos.
		Ogre::String mResourcePath;

		//OIS Input devices
		OIS::InputManager* mInputManager;
		OIS::Mouse* mMouse;
		OIS::Keyboard* mKeyboard;

		/// Establece la configuración.
		virtual bool setup();

		/// Configura la aplicación.
		bool configure();

		/// Selecciona el SceneManager.
		void chooseSceneManager();

		/// Crea la cámara.
		void crearCamara();

		/// Crea la escena del juego.
		void crearEscena();

		/// Destruye la escena del juego.
		void destruirEscena();

		/// Crea los viewports.
		void crearViewports();

		/// Método que definirá el código de los recursos.
		void setupResources();

		/// Crea resourceListener
		void createResourceListener();

		/// Carga los recursos.
		void cargarRecursos();


		/// Adjust mouse clipping area
		virtual void windowResized(RenderWindow* rw)
		{
			unsigned int width, height, depth;
			int left, top;
			rw->getMetrics(width, height, depth, left, top);

			const OIS::MouseState &ms = mMouse->getMouseState();
			ms.width = width;
			ms.height = height;
		}

		/// Unattach OIS before window shutdown (very important under Linux)
		virtual void windowClosed(RenderWindow* rw)
		{
			//Only close for window that created OIS (the main window in these demos)
			if( rw == mWindow )
			{
				if( mInputManager )
				{
					mInputManager->destroyInputObject( mMouse );
					mInputManager->destroyInputObject( mKeyboard );

					OIS::InputManager::destroyInputSystem(mInputManager);
					mInputManager = 0;
				}
			}
		}
		
		// Override frameRenderingQueued event to process that (don't care about frameEnded)
		bool frameRenderingQueued(const FrameEvent& evt)
		{

			if(mWindow->isClosed())	return false;

			//Need to capture/update each device
			mKeyboard->capture();
			mMouse->capture();

			return true;
		}

		/// Final del frame.
		bool frameEnded(const FrameEvent& evt)
		{
			return true;
		}
		
};
		
#endif
