#ifndef __MenuState__
#define __MenuState__

#include <vector>
#include<SDL_mixer.h>
#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState
{
public:

	virtual void update();
	virtual void render();
	virtual void handleState() {};
	Mix_Music* music;//FOR ADDING MUSIC IN MENUSTATE
	Mix_Chunk* chunk;//FOR SOUND EFFECTS
	virtual bool onEnter();  
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }


private:

	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	
	static void s_menuToPlay();
	static void s_exitFromMenu();
};

#endif // __MenuState__
