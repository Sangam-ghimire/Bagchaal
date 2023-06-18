#include <string>
#include <iostream>
#include <map>
 #include "MenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"
#include "AnimatedGraphic.h" 


const std::string MenuState::s_menuID = "MENU";
/*
*	This function is used to update the menu state.
*/
void MenuState::update()
{	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	
} 

//This function is used to render the menu state.
void MenuState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	//CODE FOR LOADING IMAGES IN MENUSTATE
	if (!TheTextureManager::Instance()->load("assets/start.png","playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	//CODE FOR LOADING IMAGES IN MENUSTATE
	if (!TheTextureManager::Instance()->load("assets/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	//	CODE FOR LOADING IMAGES IN MENUSTATE
	if (!TheTextureManager::Instance()->load("assets/title.png", "titletext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	//CODE FOR PLAYING MUSIC IN MENUSTATE
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	music = Mix_LoadMUS("asstes/menuMusic.mp3");

	chunk=Mix_LoadWAV("assets/menuMusic.mp3");
	Mix_PlayMusic(music, -1);
	GameObject* titleText = new AnimatedGraphic(new LoaderParams(00, 00, 1200,1200 , "titletext"), 1);
	GameObject* button1 = new MenuButton(new LoaderParams(680, 451, 247, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(680, 600, 247, 100, "exitbutton"), s_exitFromMenu);
	m_gameObjects.push_back(titleText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "Entering MenuState\n";
	return true;
}

//This function is used to exit the menu state.
bool MenuState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]-> clean();
	}
	m_gameObjects.clear();
	//CODE FOR CLEARING IMAGES IN MENUSTATE
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	TheTextureManager::Instance()->clearFromTextureMap("titletext");


	//CODE FOR STOPPPING TO PLAY MUSIC
	Mix_FreeMusic(music);
	Mix_FreeChunk(chunk);
	std::cout << "exiting MenuState\n";
	
	return true;
}
//This function is used to play the menu state.
void MenuState::s_menuToPlay()
{ 
	//CODE FOR PLAYING SOUND EFFECTS
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("assets/BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("assets/BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
//This function is used to exit the menu state.
void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}