#ifndef __PauseState__
#define __PauseState__

#include "GameState.h"
#include <vector>
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "MenuButton.h"
#include <SDL_mixer.h>

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual void handleState() {};
	virtual std::string getStateID() const { return s_pauseID; }
	Mix_Music* music;
	Mix_Chunk* chunk;

	static void s_pauseToMain();
	static void s_resumePlay();
	
private:
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
};
#endif