#include "PauseState.h"
#include "iostream"
#include "AnimatedGraphic.h"

const std::string PauseState::s_pauseID = "PAUSE";

//	This function is used to handle the pause to main.
void PauseState::s_pauseToMain()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("assets/BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("assets/BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
	TheGame::Instance()->getStateMachine()->changeState(new
		MenuState());
}
//	This function is used to change the state from pause state to play state.
void PauseState::s_resumePlay()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("assets/BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("assets/BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
	TheGame::Instance()->getStateMachine()->popState();
}
//This function is used to handle update during the pause state.
void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
//This function is used to render the images in pause state.
void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
//This function is used to load the images in pause state.
bool PauseState::onEnter()
{
	//CODE FOR LOADING IMAGES IN PAUSESTATE
	if (!TheTextureManager::Instance()->load("assets/resume.png",
		"resumebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/menu.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/title1.png", "titletext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	music = Mix_LoadMUS("assets/SHER.mp3");

	chunk = Mix_LoadWAV("assets/SHER.mp3");
	Mix_PlayMusic(music, -1);
	
	GameObject* titleText = new AnimatedGraphic(new LoaderParams(00, 00, 1200, 1200, "titletext"), 1);
	GameObject* button1 = new MenuButton(new LoaderParams(335, 275, 247, 100, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(335, 515, 247, 100, "resumebutton"), s_resumePlay);
	m_gameObjects.push_back(titleText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "Entering PauseState\n";
	return true;
}

// on exit logic
bool PauseState::onExit()
{
	// clear the texture manager
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	Mix_FreeMusic(music);
	Mix_FreeChunk(chunk);
	TheTextureManager::Instance()
		->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}

