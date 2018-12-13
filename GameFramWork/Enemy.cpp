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
		//Colletent::Instance()->setPostion2(m_position.getX(), m_position.getY(), m_height, m_width);
		/*if (Colletent::Instance()->getColletent())
		{
			coll = true;
		}*/
		

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
}
void Enemy::handleInput()
{

}
bool Enemy::returncoll()
{
	return coll;
}