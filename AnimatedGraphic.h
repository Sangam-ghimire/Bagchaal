
#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include "SDLGameObject.h"
#include "LoaderParams.h"

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
