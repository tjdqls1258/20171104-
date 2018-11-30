#pragma once
#include "LoaderParams.h"
#include "SDLGameObject.h"
class AnimatedGraphic : public SDLGameObject
{
private:
	int m_animSpeed;
	int m_numFrames = 2;
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	//virtual void draw() { ; }
	virtual void update();
	//virtual void clean() { ; }
};
