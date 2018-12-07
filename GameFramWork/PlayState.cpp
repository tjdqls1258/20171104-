#include "PlayState.h"
#include "TextureManger.h"
#include "Game.h"
#include "InputHandler.h"
#include"PauseState.h"
#include"Enemy.h"
#include"GameOverState.h"
#include "SDLGameObject.h"
#include <ctime>

PlayState* PlayState::s_pInstance = nullptr;
const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(
			PauseState::Instance());
	}
	else {
		for (int i = 0; i < m_gameObjects.size(); i++) {
			m_gameObjects[i]->update();
			if (checkCollision(
				dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
				dynamic_cast<SDLGameObject*>(m_gameObjects[i])) && (i != 0))
			{
				TheGame::Instance()->getStateMachine()->pushState(
					GameOverState::Instance());
			}
		}
		Timer += 1;
		if (Timer >= 60)
		{
			instance_enemy(1300, rand() % 590, 128, 55);
			Timer = 0;
		}
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	srand((unsigned int)time(NULL));
	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
		"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);

	instance_enemy(1300, 100, 128, 55);
	
	std::cout << "entering PlayState\n";
	return true;
}

void PlayState::instance_enemy(int x, int y, int w, int h)
{
	GameObject* enemy = new Enemy(
		new LoaderParams(x, y, w, h, "helicopter2"));

	m_gameObjects.push_back(enemy);
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}