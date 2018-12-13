#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
private:
	void handleInput();
	int dely = 0;
	int speed = 20;
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual std::string get_textID() { return m_textureID; }
};