#include "SDL.h"
#include "AnimatedGraphic.h"

/*
* AnimatedGraphic.cpp is the source file for the AnimatedGraphic class, which is a child of the SDLGameObject class.
*/

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) : SDLGameObject(pParams), m_animSpeed(animSpeed)
{
}

void AnimatedGraphic::draw()
{
	SDLGameObject::draw();
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 1));
}

void AnimatedGraphic::clean()
{
}