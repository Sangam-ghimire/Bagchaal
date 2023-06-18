#include <string>
#include "SDL.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "Board.h"
#include<iostream>
#include "PlayState.h"
#include "Game.h"


//extern int gameTurn;

/*
*	Enemy.cpp is the source file for the Enemy class.
*/

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {
	
}

/*
* This function is used to draw the enemy.
*/

void Enemy::draw()
{
	SDLGameObject::draw();
}

/*
* This function is used to update the enemy.
*/

void Enemy::update()
{  
	
	m_currentFrame = int(((SDL_GetTicks() / 100)%1 ));
	
	
}

/*
*	This function is used to handle the input of the enemy.
*/

void Enemy::handleInput() {

	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	int x = TheBoard::Instance()->filterX(pMousePos->getX());
	int y= TheBoard::Instance()->filterY(pMousePos->getY());

	m_position.setX(x);
	m_position.setY(y);
	
}

int* Enemy::handle() {
	int  r[2];
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	int x = TheBoard::Instance()->filterX(pMousePos->getX());
	int y = TheBoard::Instance()->filterY(pMousePos->getY());
	r[0] = x;
	r[1] = y;

	return r;
}
/*
* This function is used to clean the enemy.
*/
void Enemy::clean() {}
