#ifndef __MenuButton__
#define __MenuButton__
/*
* MenuButton.h is the header file for the MenuButton class, which is a child of the SDLGameObject class.
*/

#include "LoaderParams.h"
#include "SDLGameObject.h"

class MenuButton : public SDLGameObject
{
public:

	MenuButton(const LoaderParams* pParams, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void handleInput() {  };


private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	void(*m_callback)();
	bool m_bReleased;
};

#endif // __MenuButton__
