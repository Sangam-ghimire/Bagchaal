#pragma once
#include<iostream>
#include<sdl.h>
#include<map>
/*
*	GameObject.h is the header file for the GameObject class.
*/


class TextureManager {
private:
	static TextureManager* s_pInstance;
	TextureManager() {}

public:
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	//draw
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	//DRAW FRAME
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	std::map<std::string, SDL_Texture*> m_textureMap;

	static TextureManager* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new TextureManager();
			return s_pInstance;
		} /* function checks whether we already have an instance of our
		   *texturemanager if not it creates one else simply return the static instance
		   */
	}

};
