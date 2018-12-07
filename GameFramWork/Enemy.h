#include "GameObject.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	void handleInput();
	int m_numFrames = 5;
	int Speed;
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};