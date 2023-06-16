#ifndef __GameOverState__
#define __GameOverState__

#include <vector>
#include <string>
#include<SDL_mixer.h>>
#include "GameState.h"

class GameObject;

class GameOverState : public GameState
{
public:
	Mix_Music* music;
	Mix_Chunk* chunk;
	virtual void update();
	virtual void render();
	virtual void handleState() {};

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; }

private:
	static void s_gameOverToMain();
	static void s_restartPlay();

	static const std::string s_gameOverID;

	std::vector<GameObject*> m_gameObjects;
};

#endif // __GameOverState__
