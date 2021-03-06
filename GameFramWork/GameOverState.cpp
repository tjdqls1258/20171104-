#include "GameOverState.h"
#include"Game.h"
#include"MenuState .h"
#include"PlayState.h"
#include "TextureManger.h"
#include"AnimatedGraphic.h"
#include"MenuButton.h"
#include <sstream>
#include "UITextureManger.h"
const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState* GameOverState::s_pInstance = nullptr;

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		MenuState::Instance());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		PlayState::Instance());
}
bool GameOverState::onEnter()
{
	
	if (!TheTextureManager::Instance()->load("assets/gameover.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	if (!TheUITextureManager::Instance()->load(24, TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphic(
		new  LoaderParams(520, 100, 190, 30, "gameovertext"), 2);

	GameObject* button1 = new MenuButton(
		new LoaderParams(520, 200, 200, 80, "mainbutton"),
		s_gameOverToMain);

	GameObject* button2 = new MenuButton(
		new LoaderParams(520, 300, 200, 80, "restartbutton"),
		s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	
	std::cout <<"Score : " << PlayState::Instance()->retrunscore()<<"\n";


	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting GameOverState\n";
	return true;
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	std::ostringstream ostr;
	ostr << "Score : " << PlayState::Instance()->retrunscore();
	std::string s = ostr.str();
	TheUITextureManager::Instance()->draw(540, 500, 200, 100 ,TheGame::Instance()->getRenderer(), color, s);
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}