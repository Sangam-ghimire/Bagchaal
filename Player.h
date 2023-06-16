#ifndef __Player__
#define __Player__

#include <string>

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:

	Player(const LoaderParams* pParams);

	void draw();
	void handleInput();
	void clean();
	void update();
	void handle(int ,int );
	int x, y;
	
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	bool m_bReleased;
	
};

#endif // __Player__
