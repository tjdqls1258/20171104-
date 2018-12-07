#include "PlayState.h"
#include "GameStateMachine.h"
#include "MenuState .h"
#include "MenuButton.h"
#include "Game.h"
#include <iostream>
#include"TextureManger.h"

MenuState* MenuState::s_pInstance = nullptr;
const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	m_BackGround->draw();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/BackGround.png",
		"BackGround", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	m_BackGround = new SDLGameObject(new LoaderParams(0, 0, 1280, 640, "BackGround"));

	GameObject* button1 = new MenuButton(
		new LoaderParams(420, 200, 400, 100, "playbutton"),
		s_menuToPlay);

	GameObject* button2 = new MenuButton(
		new LoaderParams(420, 350, 400, 100, "exitbutton"),
		s_exitFromMenu);
	
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";

	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	m_BackGround->clean();
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	TheTextureManager::Instance()->clearFromTextureMap("BackGround");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
}