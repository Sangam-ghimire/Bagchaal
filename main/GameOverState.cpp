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

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	std::cout << "Gamover render" << std::endl;
}

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
	music = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/gameover.WAV");

	chunk = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/gameover.WAV");
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
	TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");

	std::cout << "exiting GameOverState" << std::endl;;
	return true;
}

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
}

void GameOverState::s_restartPlay()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);

	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
