#include <string>
#include "SDL.h"

#include "Player.h"
#include "InputHandler.h"
#include <iostream>
#include "Board.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{

	SDLGameObject::draw();
	
}
void Player::update()
{
	//handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

	//SDLGameObject::update();
}



void Player::handleInput()
{
	
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	int x = TheBoard::Instance()->filterX(pMousePos->getX());
	int y = TheBoard::Instance()->filterY(pMousePos->getY());

	m_position.setX(x);
	m_position.setY(y);
}

void Player::clean() {}
