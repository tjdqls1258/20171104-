#pragma once
#include "SDLGameObject.h"

class Bullte : public SDLGameObject
{
private:
	void handleInput();
	bool coll = false;
	int speed;
public:
	Bullte(const LoaderParams* pParams, int speed);
	virtual void draw();
	virtual void update();
	virtual void clean();
	bool returncoll();

};