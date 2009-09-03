/// Fichero de cabecera de la clase InterfazGFX.
/** \file InterfazGFX.h
 */
	
#ifndef _INTERFAZGFX_H_
#define _INTERFAZGFX_H

#include "Ogre.h"
#include "OgreConfigFile.h"
#include "FrameListener.h"
#include <iostream>

using namespace std;
using namespace Ogre;


/** Interfáz gráfica del juego que se ocupa de interactuar con Ogre.
*/
class InterfazGFX
{
	public:

            /// Obtiene la instancia.
            static InterfazGFX* getInstancia();
	    
	    /// Destructor por defecto.
	    ~InterfazGFX();
	
	    /// Inicia la interfaz.
	    void iniciar();
	    
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
	    
	    /// Pura mierda.
	    ExampleFrameListener* mFrameListener;
	    
	    /// Ventana.
	    RenderWindow* mWindow;
		
            /// Ruta de los recursos.
            Ogre::String mResourcePath;
	
	    /// Establece la configuración.
	    virtual bool setup();
	    
	    /// Configura la aplicación.
	    bool configure();
	
            /// Selecciona el SceneManager.
	    void chooseSceneManager();

            /// Crea la cámara.
	    void crearCamara();
	
            /// Pura mierda.
	    void createFrameListener();

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
	
	protected:
		
};
		
#endif
