#include "Bullte.h"
#include "InputHandler.h"
#include "Game.h"
#include "Enemy.h"

Bullte::Bullte(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
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
		m_position.setX(m_position.getX() + 1);
		m_currentFrame = 0;
		SDLGameObject::update();
	}
}
void Bullte::clean()
{
	coll = true;
	m_position.setX(-999.0f);
	m_position.setY(-999.0f);
}

void Bullte::handleInput()
{

}