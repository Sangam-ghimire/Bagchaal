
#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"
#include "LoaderParams.h"

/*
* AnimatedGraphic.h is the header file for the AnimatedGraphic class, which is a child of the SDLGameObject class.
*/

class AnimatedGraphic : public SDLGameObject
{
public:

	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void handleInput() {};

private:
	int m_animSpeed;
};
#endif
