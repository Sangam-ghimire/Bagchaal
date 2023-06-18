#ifndef __InputHandler__
#define __InputHandler__

#include <vector>
#include <utility>

#include "SDL.h"
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if(s_pInstance == nullptr)
		{
			s_pInstance = new InputHandler();
		}
		
		return s_pInstance;
	}
	
	void update();
	void clean();
	
	
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}	
	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}
	bool isKeyDown(SDL_Scancode key);
	Vector2D* m_mousePosition;
	void reset();
private:
	InputHandler();
	~InputHandler() { delete m_mousePosition; }
	
	static InputHandler* s_pInstance;
	
	
	std::vector<std::vector<bool>> m_buttonStates;
	std::vector<bool> m_mouseButtonStates;
	
	const Uint8* m_keystates;
	
	
	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
	
	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);
	
	
};
typedef InputHandler TheInputHandler;

#endif // __InputHandler__
