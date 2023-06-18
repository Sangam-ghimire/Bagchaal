#include <string>
#include "SDL.h"

#include "Player.h"
#include "InputHandler.h"
#include <iostream>
#include "Board.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
	
void Player::draw()
{
	// draw the player
	SDLGameObject::draw();
	
}


void Player::update()
{
	//handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

	//SDLGameObject::update();
}


//	Handle the player's input.
void Player::handleInput()
{
	// get the current mouse position
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	int x = TheBoard::Instance()->filterX(pMousePos->getX());
	int y = TheBoard::Instance()->filterY(pMousePos->getY());
	// set the velocity to go left
	m_position.setX(x);
	m_position.setY(y);
}

//	This function is used to clean the player.
void Player::clean() {}
