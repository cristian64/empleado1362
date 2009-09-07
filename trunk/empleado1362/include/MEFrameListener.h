#ifndef _MEFRAMELISTENER_H_
#define _MEFRAMELISTENER_H_

#include "Ogre.h"
#include "OgreStringConverter.h"
#include "OgreException.h"
#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>
#include <iostream>

using namespace std;
using namespace Ogre;

class MEFrameListener: public FrameListener, public WindowEventListener
{
	public:
		/// Constructor
		MEFrameListener(RenderWindow* mWindow, OIS::Keyboard* mKeyboard, OIS::Mouse* mMouse)
		{
			this->mWindow = mWindow;
			this->mKeyboard = mKeyboard;
			this->mMouse = mMouse;

			//Set initial mouse clipping size
			windowResized(mWindow);

			//Register as a Window listener
			WindowEventUtilities::addWindowEventListener(mWindow, this);
		}

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

		/// Destructor.
		virtual ~MEFrameListener()
		{
			//Remove ourself as a Window listener
			WindowEventUtilities::removeWindowEventListener(mWindow, this);
			windowClosed(mWindow);
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

	private:

	RenderWindow* mWindow;

	//OIS Input devices
	OIS::InputManager* mInputManager;
	OIS::Mouse* mMouse;
	OIS::Keyboard* mKeyboard;	
};

#endif
