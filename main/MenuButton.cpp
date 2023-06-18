#include "MenuButton.h"
#include "Vector2D.h"
#include "InputHandler.h"
/*
*	MenuButton.cpp is the implementation file for the MenuButton class.
*/
MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) : SDLGameObject(pParams), m_callback(callback) 
{
	m_currentFrame = MOUSE_OUT; // start at frame 0
}
// This function is used to draw the menu button.
void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}
// This function is used to update the menu button.
void MenuButton::update()
{
	// get the current mouse position
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
	
	if(pMousePos->getX() < (m_position.getX() + m_width)
	  && pMousePos->getX() > m_position.getX()
	  && pMousePos->getY() < (m_position.getY() + m_height)
	  && pMousePos->getY() > m_position.getY())
	{
		
		
		if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{

			m_currentFrame = CLICKED;
			m_callback(); // call our callback function
			m_bReleased = false;
		
		}
	else if (!TheInputHandler::Instance() ->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}
// This function is used to clean the menu button.
void MenuButton::clean()
{
	// call the base class clean function
	SDLGameObject::clean();
}
