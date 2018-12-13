#include "Player.h"
#include "InputHandler.h"
#include "PlayState.h"
#include "BullteManger.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	if (dely >= 0)
	{
		dely -= 1;
	}
	else
	{
		dely = 0;
	}
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	handleInput();
	SDLGameObject::update();
}
void Player::clean()
{
}
void Player::handleInput()
{
	
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
	if (m_velocity.getX() >= 0)
	{
		speed = 5;
	}
	else
	{
		speed = -5;
	}
	if ((dely == 0) && (TheInputHandler::Instance()->getMouseButtonState(LEFT)))
	{
		BullteManger::Instance()->instance_bullte(m_position.getX() + 64, m_position.getY() + 16, speed);
		dely = 30;
	}
}
