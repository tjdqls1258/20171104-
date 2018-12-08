#include "BackGround.h"
#include "InputHandler.h"
BackGround::BackGround(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void BackGround::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void BackGround::update()
{
	m_velocity.setX(-2);
	if (m_position.getX() <= -1280)
	{
		m_position.setX(1280);
	}
	SDLGameObject::update();
}
void BackGround::clean()
{
}
void BackGround::handleInput()
{
}
