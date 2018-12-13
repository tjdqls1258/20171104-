#include "UITextureManger.h"
#include <string.h>
UITextureManger* UITextureManger::s_pInstance = nullptr;
bool UITextureManger::load(int font_size, SDL_Color color, SDL_Renderer* pRenderer, std::string say)
{
	char buf[100];
	strncpy_s(buf, say.c_str(), say.size());
	font = TTF_OpenFont("assets/HMKMAMI.ttf", font_size);
	if (!font) {
		return false;
	}
	surfaceMessage = TTF_RenderText_Solid(font, buf, color);
	Message = SDL_CreateTextureFromSurface(pRenderer, surfaceMessage);
	if (Message != 0)
	{
		return true;
	}
	return false;
}
void UITextureManger::draw(
	int x, int y, int width, int height,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, Message,
		&srcRect, &destRect, 0, 0, flip);
}