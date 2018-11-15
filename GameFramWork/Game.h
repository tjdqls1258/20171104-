#pragma once
#include "Player.h"
#include <vector>

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	std::vector<GameObject*> m_gameObjects;
	bool m_bRunning = true;

	int m_currentFrame;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

};