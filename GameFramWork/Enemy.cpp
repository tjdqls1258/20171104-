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
	if (!coll)
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
	
}

void Enemy::draw()
{
	if (!coll)
	{
		SDLGameObject::draw();
	}
}
void Enemy::clean()
{
	coll = true;
	m_position.setX(-999.0f);
	m_position.setY(-999.0f);
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