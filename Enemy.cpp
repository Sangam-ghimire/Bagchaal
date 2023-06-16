#include <string>
#include "SDL.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "Board.h"
#include<iostream>
#include "PlayState.h"
#include "Game.h"


//extern int gameTurn;

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {
	
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{  
	
	m_currentFrame = int(((SDL_GetTicks() / 100)%1 ));
	
	
}

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


void Enemy::clean() {}
