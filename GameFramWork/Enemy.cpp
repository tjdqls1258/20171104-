#include "Enemy.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include <ctime>

Enemy::Enemy(const LoaderParams* pParams, int Speed,int ySpeed) : SDLGameObject(pParams)
{
	srand((unsigned int)time(NULL));
	this->Speed = Speed;
	this->ySpeed = ySpeed;
}
void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (Speed != 0)
	{
		m_velocity.setX(-Speed);
	}
	if (ySpeed != 0)
	{
		m_velocity.setY(ySpeed);
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