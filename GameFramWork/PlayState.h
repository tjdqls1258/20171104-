#pragma once
#include "GameState.h"

class SDLGameObject;
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	virtual std::string getStateID() const { return s_playID; }
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_gameObjects;
	GameObject* m_BackGround;
	void instance_enemy(int x, int y, int w, int h);
	PlayState() {}
	int Timer = 0;
};