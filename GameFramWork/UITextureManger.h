#pragma once
#include<SDL_ttf.h>
#include "SDL.h"
#include <iostream>
#include <map>

class UITextureManger
{
private:
	UITextureManger() {}
	static UITextureManger *s_pInstance;
	SDL_Surface* surfaceMessage;
	TTF_Font* font;
	SDL_Texture* Message;
	SDL_Rect Message_rect;
public:
	std::map<std::string, SDL_Texture*> UI_textureMap;
	static UITextureManger* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new UITextureManger();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool load(int font_size, SDL_Color color, SDL_Renderer* pRenderer, std::string say);

	void draw(int x, int y, int width, int height,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

};

typedef UITextureManger TheUITextureManager;