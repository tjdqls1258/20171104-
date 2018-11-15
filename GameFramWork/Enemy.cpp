#include "Enemy.h"
#include "LoaderParams.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}
void Enemy::update()
{
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);
	SDLGameObject::update();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	handleInput();
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