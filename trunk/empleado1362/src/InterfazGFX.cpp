/// Fichero de definición de la clase InterfazGFX.
/** \file InterfazGFX.cpp
 */

#include "InterfazGFX.h"
#include "InterfazPSX.h"
#include <iostream>
#include <OGRE/OgreRoot.h>
     
using namespace std;

InterfazGFX* InterfazGFX::instancia = NULL;

// Constructor por defecto.
InterfazGFX::InterfazGFX()
{
	// Nodo raíz.
	mRoot = 0;
}

// Destructor por defecto.
InterfazGFX::~InterfazGFX()
{
	if (mRoot != NULL)
		OGRE_DELETE mRoot;

	//Remove ourself as a Window listener
	WindowEventUtilities::removeWindowEventListener(mWindow, this);
	windowClosed(mWindow);

	instancia = NULL;
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
}

// Actualiza la interfaz gráfica.
void InterfazGFX::actualizar()
{
	float x = InterfazPSX::getInstancia()->posicionPavicoX();
	float y = InterfazPSX::getInstancia()->posicionPavicoY();
	float z = InterfazPSX::getInstancia()->posicionPavicoZ();
	mSceneMgr->getRootSceneNode()->getChild("nodo_protagonista")->setPosition(x, y, z);
}



// Dibuja la escena.
bool InterfazGFX::dibujar() const
{
	// Dibujamos un frame.
	mRoot->renderOneFrame();
}

// Obtiene el mInput Manager.
OIS::InputManager* InterfazGFX::getmInputManager() const
{
	return mInputManager;
}

// Establece el mInput Manager.
void InterfazGFX::setmInputManager(OIS::InputManager* mInputManager)
{
	this->mInputManager = mInputManager;
}

// Obtiene el mMouse.
OIS::Mouse* InterfazGFX::getmMouse() const
{
	return mMouse;
}

// Establece el mMouse.
void InterfazGFX::setmMouse(OIS::Mouse* mMouse)
{
	this->mMouse = mMouse;
}

// Obtiene el mKeyboard.
OIS::Keyboard* InterfazGFX::getmKeyboard() const
{
	return mKeyboard;
}

// Establece el mKeyboard.
void InterfazGFX::setmKeyboard(OIS::Keyboard* mKeyboard)
{
	this->mKeyboard = mKeyboard;
}

// Establece todos los input devices.
void InterfazGFX::setInputDevices(OIS::InputManager* mInputManager, OIS::Mouse* mMouse, OIS::Keyboard* mKeyboard)
{
	setmInputManager(mInputManager);
	setmMouse(mMouse);
	setmKeyboard(mKeyboard);
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

	// Iniciamos los input devices
	LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
	OIS::ParamList pl;
	size_t windowHnd = 0;
	std::ostringstream windowHndStr;
	mWindow->getCustomAttribute("WINDOW", &windowHnd);
	windowHndStr << windowHnd;
	pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
	mInputManager = OIS::InputManager::createInputSystem( pl );
	
	//Create all devices (We only catch joystick exceptions here, as, most people have Key/Mouse)
	mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, false ));
	mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, false ));
	
	//Set initial mouse clipping size
	windowResized(mWindow);

	//Register as a Window listener
	WindowEventUtilities::addWindowEventListener(mWindow, this);

	mRoot->addFrameListener(this);

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
	// Create the SceneManager de interior.
	mSceneMgr = mRoot->createSceneManager(ST_INTERIOR, "EscenaInterior");
}

// Crea la cámara.
void InterfazGFX::crearCamara()
{
	// Create the camera
	mCamera = mSceneMgr->createCamera("PlayerCam");

	// Position it at 500 in Z direction
	mCamera->setPosition(Vector3(0,100,500));
	// Look back along -Z
	mCamera->lookAt(Vector3(0,0,0));
	mCamera->setNearClipDistance(5);

}

// Crea la escena.
void InterfazGFX::crearEscena()
{
	// Activamos las sombras
	mSceneMgr->setShadowTechnique(SHADOWTYPE_STENCIL_ADDITIVE);

	// Activamos la luz ambiente
	mSceneMgr->setAmbientLight(ColourValue(1, 1, 1));

	// Suelo1
	Entity* ent_oficina_suelo1[10];
	for( int i=0; i<10; i++)
	{
		ent_oficina_suelo1[i] = mSceneMgr->createEntity("ent_oficina_suelo1_"+i,"oficina_suelo1.mesh");
		ent_oficina_suelo1[i]->setCastShadows(false);
	}

	SceneNode* nod_oficina_suelo1[10];
	
	for( int i=0; i<10; i++)
	{
		nod_oficina_suelo1[i] = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodo_oficina_suelo1_"+i);
		nod_oficina_suelo1[i]->attachObject(ent_oficina_suelo1[i]);
		nod_oficina_suelo1[i]->scale(10,10,10);
		int posX = (80*(i%5))-400;
		int posY = 0;
		int posZ = (80*(i/5))-100;
		nod_oficina_suelo1[i]->setPosition(Vector3( posX ,posY, posZ));
		nod_oficina_suelo1[i]->pitch( Degree(-90));
	}

	// Suelo2
	Entity* ent_oficina_suelo2[10];
	for( int i=0; i<10; i++)
	{
		ent_oficina_suelo2[i] = mSceneMgr->createEntity("ent_oficina_suelo2_"+i,"oficina_suelo2.mesh");
		ent_oficina_suelo2[i]->setCastShadows(false);
	}

	SceneNode* nod_oficina_suelo2[10];

	for( int i=0; i<10; i++)
	{
		nod_oficina_suelo2[i] = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodo_oficina_suelo2_"+i);
		nod_oficina_suelo2[i]->attachObject(ent_oficina_suelo2[i]);
		nod_oficina_suelo2[i]->scale(10,10,10);
		int posX = (80*(i%5));
		int posY = 0;
		int posZ = (80*(i/5))-100;
		nod_oficina_suelo2[i]->setPosition(Vector3( posX ,posY, posZ));
		nod_oficina_suelo2[i]->pitch( Degree(-90));
	}
	
	// Pared1
	Entity* ent_oficina_pared1[10];

	for( int i=0; i<10; i++)
	{
		ent_oficina_pared1[i] = mSceneMgr->createEntity("ent_oficina_pared1_"+i,"oficina_pared1.mesh");
		ent_oficina_pared1[i]->setCastShadows(false);
	}

	SceneNode* nod_oficina_pared1[10];

	for( int i=0; i<10; i++)
	{
		nod_oficina_pared1[i] = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodo_oficina_pared1_"+i);
		nod_oficina_pared1[i]->attachObject(ent_oficina_pared1[i]);
		nod_oficina_pared1[i]->scale(10,10,10);
		int posX = (80*2*(i%5))-400;
		int posY = 80*(i/5);
		int posZ = -140;
		nod_oficina_pared1[i]->setPosition(Vector3( posX ,posY, posZ));
		nod_oficina_pared1[i]->pitch( Degree(-90));
	}

	// Pared3
	Entity* ent_oficina_pared3[10];

	for( int i=0; i<10; i++)
	{
		ent_oficina_pared3[i] = mSceneMgr->createEntity("ent_oficina_pared3_"+i,"oficina_pared3.mesh");
		ent_oficina_pared3[i]->setCastShadows(false);
	}

	SceneNode* nod_oficina_pared3[10];

	for( int i=0; i<10; i++)
	{
		nod_oficina_pared3[i] = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodo_oficina_pared3_"+i);
		nod_oficina_pared3[i]->attachObject(ent_oficina_pared3[i]);
		nod_oficina_pared3[i]->scale(10,10,10);
		int posX = (80*2*(i%5))-480;
		int posY = 80*(i/5);
		int posZ = -140;
		nod_oficina_pared3[i]->setPosition(Vector3( posX ,posY, posZ));
		nod_oficina_pared3[i]->pitch( Degree(-90));
	}

	// Luz
	Light* light = mSceneMgr->createLight("lusesica");
	light->setType(Light::LT_POINT);
	light->setPosition(Vector3(100,150,300));
	light->setDiffuseColour(0.4, 0.4, 0.4);
	light->setSpecularColour(0.2, 0.2, 0.2);

	// Protagonista
	Entity* ent_protagonista = mSceneMgr->createEntity("ent_protagonista","protagonista.mesh");
	SceneNode* nod_protagonista = mSceneMgr->getRootSceneNode()->createChildSceneNode("nodo_protagonista");
	nod_protagonista->attachObject(ent_protagonista);
	nod_protagonista->scale(15,15,15);
	nod_protagonista->setPosition(-300,0,-100);
	nod_protagonista->yaw( Degree(90));
	nod_protagonista->pitch( Degree(-90));
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
	vp->setBackgroundColour(ColourValue(0,0,0));

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
