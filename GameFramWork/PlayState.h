#pragma once
#include "GameState.h"
#include <sstream>
class SDLGameObject;
class PlayState : public GameState
{
public:
	float retrunscore();
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
	std::vector<GameObject*> m_gameObjects;
	bool checkOutSide(SDLGameObject* p1);
private:
	std::string s;
	SDL_Color color = { 255,255,255 };
	
	static const std::string s_playID;
	static PlayState* s_pInstance;
	std::vector<GameObject*> m_BackGround;
	void instance_enemy(int x, int y, int w, int h, int xSpeed, int ySpeed);
	void instance_BackGround(int x, int y, int w, int h);
	PlayState() {}
	float Timer = 0.0f;
	float dley = 0.0f;
	float score = 0.0f;
};