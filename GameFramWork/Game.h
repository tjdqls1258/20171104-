#pragma once
#include "Player.h"
#include <vector>
#include "GameStateMachine.h"
//#include "GameStateMachine.h"
class Game
{
public:
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	
	void quit();
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
private:
	Game() {}
	static Game* s_pInstance;
	SDL_Window * m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	std::vector<GameObject*> m_gameObjects;
	bool m_bRunning = true;
	GameStateMachine* m_pGameStateMachine;
	
};

typedef Game TheGame;