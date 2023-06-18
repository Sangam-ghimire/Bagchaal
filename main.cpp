#include "Game.h"

Game * g_game = 0;



int main(int argc, char* args[])
{

	g_game = new Game();//The new operator denotes a request for memory allocation on the Free Store.
					 // If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable. 

	g_game->init("Baagchal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,640,640, SDL_WINDOW_RESIZABLE);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();


	}
	g_game->clean();

	return 0;
}