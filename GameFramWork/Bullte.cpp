#include "Bullte.h"
#include "InputHandler.h"
#include "Game.h"
#include "Enemy.h"

Bullte::Bullte(const LoaderParams* pParams, int speed) :
	SDLGameObject(pParams)
{
	this->speed = speed;
}
void Bullte::draw()
{
	if (!coll)
	{
		SDLGameObject::draw(); // we now use SDLGameObject
	}
}
void Bullte::update()
{
	if (!coll)
	{
		m_velocity.setX(speed);
		m_currentFrame = 0;
		SDLGameObject::update();
		/*if (m_position.getX() > 1280||m_position.getX()< 0)
		{
			coll = true;
		}*/
		//Colletent::Instance()->setPostion1(m_position.getX(), m_position.getY(), m_height, m_width);
		/*if (Colletent::Instance()->getColletent())
		{
			coll = true;
		}*/
	}
}
void Bullte::clean()
{
	coll = true;
	
}

void Bullte::handleInput()
{

}

bool Bullte::returncoll()
{
	return coll;
}