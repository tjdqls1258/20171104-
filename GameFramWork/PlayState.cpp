#include "PlayState.h"
#include "TextureManger.h"
#include "Game.h"
#include "InputHandler.h"
#include"PauseState.h"
#include "BackGround.h"
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
			else if (checkOutSide(dynamic_cast<SDLGameObject*>(m_gameObjects[i])) && (i != 0))
			{
				m_gameObjects[i]->clean();
			}
		}
		Timer += 1.0f;
		score += 0.01f;
		if (Timer >= (60.0f - dley))
		{
			instance_enemy(1300, rand()%580, 128, 55, rand() % 5 + 5, 0);
			Timer = 0.0f;
			if (dley != 30.0f)
			{
				dley += 0.04f;
			}
			if (dley >= 0.1f)
			{
				instance_enemy(rand() % 1300, -60, 128, 55, 0, rand() % 5 + 5);
			}
			if (dley >= 0.2f)
			{
				instance_enemy(rand() % 1300, -60, 128, 55, rand() % 5 + 5, rand() % 7 + 2);
			}
		}
		for (int j = 0; j < m_BackGround.size(); j++) {
			m_BackGround[j]->update();
		}
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_BackGround.size(); i++) {
		m_BackGround[i]->draw();
	}
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
	if (!TheTextureManager::Instance()->load("assets/back.png",
		"back", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	
	instance_BackGround(1280, 0, 1280, 640);
	instance_BackGround(0, 0, 1280, 640);
	m_gameObjects.push_back(player);
	instance_enemy(1300, 100, 128, 55,rand()%5+5,0);
	dley = 0.0f;
	score = 0.0f;
	Timer = 0.0f;
	std::cout << "entering PlayState\n";
	return true;
}

void PlayState::instance_enemy(int x, int y, int w, int h, int xSpeed, int ySpeed)
{
	GameObject* enemy = new Enemy(
		new LoaderParams(x, y, w, h, "helicopter2"), xSpeed, ySpeed);

	m_gameObjects.push_back(enemy);
}
void PlayState::instance_BackGround(int x, int y, int w, int h)
{
	GameObject* background = new BackGround(
		new LoaderParams(x, y, w, h, "back"));

	m_BackGround.push_back(background);
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

bool  PlayState::checkOutSide(SDLGameObject* p1)
{
	int x = p1->getPosition().getX();
	int out = p1->getHeight() *(-1);
	if (x < out)
	{
		return true;
	}
	return false;
}

float PlayState::retrunscore()
{
	return score * 100;
}