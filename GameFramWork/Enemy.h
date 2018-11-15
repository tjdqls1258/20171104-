#include "GameObject.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	void handleInput();
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};