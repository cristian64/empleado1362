/// Fichero de definición de la clase InterfazGFX.
/** \file InterfazGFX.cpp
 */

#include "InterfazGFX.h"
#include <iostream>

using namespace std;

InterfazGFX* InterfazGFX::instancia = NULL;

// Constructor por defecto.
InterfazGFX::InterfazGFX()
{
	// Controlador de eventos.
	mFrameListener = 0;
	
	// Nodo raíz.
	mRoot = 0;
}

// Destructor por defecto.
InterfazGFX::~InterfazGFX()
{
	// Liberamos la memoria.
	if (mFrameListener != NULL)
		delete mFrameListener;
		
	if (mRoot != NULL)
		OGRE_DELETE mRoot;
}

// Devuelve la instancia de la clase singleton.
InterfazGFX* InterfazGFX::getInstancia()
{
	if(instancia == NULL)
		instancia = new InterfazGFX();
	return instancia;
}

// Inicia la interfaz.
void InterfazGFX::iniciar()
{
	// Panel de opciones.
	if (!setup())
		return;
	
	// Dibujamos la escena.
	mRoot->startRendering();
	
	// Liberamos la escena.
	destruirEscena();
}

// Establece la configuración.
bool InterfazGFX::setup()
{
	String pluginsPath;
	// only use plugins.cfg if not static
	#ifndef OGRE_STATIC_LIB
		pluginsPath = mResourcePath + "plugins.cfg";
	#endif

	mRoot = OGRE_NEW Root(pluginsPath, mResourcePath + "ogre.cfg", mResourcePath + "Ogre.log");

	setupResources();

	bool carryOn = configure();
	if (!carryOn) return false;

	chooseSceneManager();
	crearCamara();
	crearViewports();

	// Set default mipmap level (NB some APIs ignore this)
	TextureManager::getSingleton().setDefaultNumMipmaps(5);

	// Create any resource listeners (for loading screens)
	createResourceListener();
	
	// Carga los recursos.
	cargarRecursos();

	// Crea la escena.
	crearEscena();

	createFrameListener();

	return true;
}

// Configura la aplicación.
bool InterfazGFX::configure()
{
	// Show the configuration dialog and initialise the system
	// You can skip this and use root.restoreConfig() to load configuration
	// settings if you were sure there are valid ones saved in ogre.cfg
	if(mRoot->showConfigDialog())
	{
		// If returned true, user clicked OK so initialise
		// Here we choose to let the system create a default rendering window by passing 'true'
		mWindow = mRoot->initialise(true);
		return true;
	}
	else
	{
		return false;
	}
}

// Selecciona el SceneManager.
void InterfazGFX::chooseSceneManager()
{
	// Create the SceneManager, in this case a generic one
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "ExampleSMInstance");
}

// Crea la cámara.
void InterfazGFX::crearCamara()
{
	// Create the camera
	mCamera = mSceneMgr->createCamera("PlayerCam");

	// Position it at 500 in Z direction
	mCamera->setPosition(Vector3(0,0,500));
	// Look back along -Z
	mCamera->lookAt(Vector3(0,0,-300));
	mCamera->setNearClipDistance(5);

}

// Mierda pura.
void InterfazGFX::createFrameListener()
{
	mFrameListener= new ExampleFrameListener(mWindow, mCamera);
	mRoot->addFrameListener(mFrameListener);
}

// Crea la escena.
void InterfazGFX::crearEscena()
{
	mSceneMgr->setAmbientLight(ColourValue(1, 1, 1));
	Entity *ent1 = mSceneMgr->createEntity("Pinguino", "monigote1.mesh");
	SceneNode *node1 = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoPinguino");
	node1->attachObject(ent1);
	node1->scale(100,100,100);
	node1->pitch( Degree(-90));
	
	Entity *ent2 = mSceneMgr->createEntity("Oso", "monigote2.mesh");
	SceneNode *node2 = mSceneMgr->getRootSceneNode()->createChildSceneNode("NodoOso");
	node2->attachObject(ent2);
	
	
	Light* light = mSceneMgr->createLight("lusesica");
	light->setType(Light::LT_POINT);
	light->setPosition(Vector3(0,150,300));
	light->setDiffuseColour(1.0, 1.0, 1.0);
	light->setSpecularColour(1.2, 1.2, 1.2);
}

// Destruye la escena.
void InterfazGFX::destruirEscena()
{

}

// Crea los viewports.
void InterfazGFX::crearViewports()
{
	// Crea un viewport en toda la ventana.
	Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour(ColourValue(0,0,1));

	// Altera el aspect ratio de la cámara para ajustarlo al viewport.
	mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));
}

// Método que definirá el código de los recursos.
void InterfazGFX::setupResources()
{
	// Carga los recursos desde el fichero de configuración.
	ConfigFile cf;
	cf.load(mResourcePath + "resources.cfg");

	// Go through all sections & settings in the file
	ConfigFile::SectionIterator seci = cf.getSectionIterator();

	String secName, typeName, archName;
	while (seci.hasMoreElements())
	{
		secName = seci.peekNextKey();
		ConfigFile::SettingsMultiMap *settings = seci.getNext();
		ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i)
		{
			typeName = i->first;
			archName = i->second;
			ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
	   }
   }
}

// Crea un resoruceListener
void InterfazGFX::createResourceListener()
{

}

// Carga los recursos.
void InterfazGFX::cargarRecursos()
{
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
