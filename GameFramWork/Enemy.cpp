#include "Enemy.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include <ctime>
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	srand((unsigned int)time(NULL));
	Speed = rand() % 5 +2;
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getX() > 0) {
		m_velocity.setX(-Speed);
	}
	else if (m_position.getX() < -100) {
		m_position.setX(1280);
		m_position.setY(rand() % 590);
		Speed = rand() % 5 +2;
	}
	SDLGameObject::update();
}

void Enemy::draw()
{
	SDLGameObject::draw();
}
void Enemy::clean()
{
}
void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(10);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}