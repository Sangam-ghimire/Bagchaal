#include "Game.h"

using namespace std;
//#include"TextureManager.h"

/*
* Game.cpp is the implementation file for the Game class.
*/

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";	
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";

	typedef TextureManager* TheTextureManager;

	//if (!TheTextureManager::Instance()->load("assets/sangam.bmp"), "sangamid", m_pRenderer) {
	//return false;
	//}//loads
	//TheTextureManager::Instance()->draw("sangamid", 0, 0, 128, 82, m_pRenderer);//draws
	// to load

	
	m_bRunning = true; // everything inited successfully, start the main loop
	return true;


}

/*
*	render() is the function used to render the game to the screen.
*/

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);//puts background colour


	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

/*
* handleEvents() is the function used to handle events in the game.
*/

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

/*
*	update() is the function used to update the game.
*/
void Game::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

/*
*	clean() is the function used to clean up the game.
*/
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
