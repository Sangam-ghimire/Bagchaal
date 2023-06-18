#pragma once
#include "SDL.h"
#include<SDL_image.h>
#include <iostream>
#include"TextureManager.h"
//#include"TextureManager.h"

/*
* Game.h is the header file for the Game class.
*/
*/

#ifndef __Game__
#define __Game__
class Game
{
public:
	Game() {}
	~Game() {}
	// simply set the running variable to true
	void init() { m_bRunning = true; }
	void render();
	void update();
	void handleEvents();
	void clean();
	// a function to access the private running variable 
	bool running() { return m_bRunning; }
	bool init(const char* title, int xpos, int ypos, int width, int
		height, int flags);

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;
	//TextureManager m_textureManager;
	
	bool m_bRunning;




};


#endif /* defined(__Game__) */