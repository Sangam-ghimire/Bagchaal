#include <iostream>
#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "GameOverState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "LoaderParams.h"
#include "MenuButton.h"
#include<SDL_mixer.h>

/*
*	GameOverState.cpp is the source file for the GameOverState class.
*/
const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
 		m_gameObjects[i]->update();
	}
	std::cout << "Gamover update" << std::endl;
}

/*
*	This function is used to render the game over state.
*/

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	std::cout << "Gamover render" << std::endl;
}

/*
*	This function is used to exit the game over state.
*/

bool GameOverState::onEnter()
{
	std::cout << "Gamover onEnter" << std::endl;
	if (!TheTextureManager::Instance()->load("assets/over.png", "gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/menu.png", "mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/restart.png", "restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	music = Mix_LoadMUS("gameover.WAV");

	chunk = Mix_LoadWAV("gameover.WAV");
	Mix_PlayMusic(music, -1);
	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(00, 00, 1200, 1000, "gameovertext"), 10);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 200, 247, 100, "mainbutton"), s_gameOverToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 247, 180, "restartbutton"), s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering GameOverState" << std::endl;
	return true;
}

/*
*	This function is used to exit the game over state.
*/

bool GameOverState::onExit()
{
	std::cout << "Gamover onExit" << std::endl;
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	Mix_FreeMusic(music);
	Mix_FreeChunk(chunk);
	/*	
	*	We are using the clearFromTextureMap function of the texture manager to clear the texture map.
	*/
	TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

	std::cout << "exiting GameOverState" << std::endl;;
	return true;
}

/*
*	This function is used to change the state from game over state to main menu state.
*/

void GameOverState::s_gameOverToMain()
{
/*
*	We are using the changeState function of the state machine to change the state from game over state to main menu state.
*/
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
}

/*
*	This function is used to change the state from game over state to play state.
*/

void GameOverState::s_restartPlay()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
/*
*	We are using the changeState function of the state machine to change the state from game over state to play state.
*/
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
