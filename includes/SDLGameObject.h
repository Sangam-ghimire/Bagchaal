#ifndef __SDLGameObject__
#define __SDLGameObject__

#include <string>

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"

/*
* SDLGameObject.h is the header file for the SDLGameObject class, which is a child of the GameObject class.
*/

class SDLGameObject : public GameObject
{
public:

	SDLGameObject(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean() {};

	Vector2D& getPosition() { return m_position; }

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	std::string getm_textureID() { return m_textureID; }
	//virtual void handle(int.int);

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

#endif // __SDLGameObject__
