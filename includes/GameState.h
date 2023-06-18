#ifndef __GameState__
#define __GameState__

/*
* GameState.h is the header file for the GameState class.
*/

#include <string>

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleState() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateID() const = 0;
};

#endif // __GameState__
