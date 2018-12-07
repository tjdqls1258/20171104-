#include "Player.h"
#include "InputHandler.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
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
}
