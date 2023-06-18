#include "GameStateMachine.h"

/*
*	pushState() pushes a new state onto the stack.
*/

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}
//	popState() pops the current state off the stack.
void GameStateMachine::popState()
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

//	changeState() changes the state by popping the current state off the stack and pushing the new state on.
void GameStateMachine::changeState(GameState* pState)
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}
		
		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
	
	// push back our new state
	m_gameStates.push_back(pState);
	
	// initialise it
	m_gameStates.back()->onEnter();
}

//	update() updates the current state.

void GameStateMachine::update()
{
	if(!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}

//	render() renders the current state.

void GameStateMachine::render()
{
	if(!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}
