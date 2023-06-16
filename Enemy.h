#ifndef __Enemy__
#define __Enemy__

#include <string>

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:

	Enemy(const LoaderParams* pParams);

	void draw();
	void update();
	void handleInput();
	void clean();
	int * handle();
	

};

#endif // __Enemy__
