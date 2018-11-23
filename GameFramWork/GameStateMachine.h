#pragma once
#include "GameState.h"
class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();
	GameState* return_mcurrentState()
	{
		return m_currentState;
	}
	GameStateMachine() {  }
private:
	GameState * m_currentState;
	GameState* m_prevState;
};