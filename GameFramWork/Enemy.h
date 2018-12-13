#include "GameObject.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	void handleInput();
	int m_numFrames = 5;
	int Speed;
	int ySpeed;
	bool coll = false;
public:
	Enemy(const LoaderParams* pParams, int ySpeed, int Speed);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual std::string get_textID() { return m_textureID; }
	bool returncoll();
};