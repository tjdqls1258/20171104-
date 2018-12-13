#include "Colletent.h"


Colletent* Colletent::s_pInstance = 0;

//Colletent::Colletent()
//{
//}
//
//
//Colletent::~Colletent()
//{
//}
//void Colletent::setPostion1(int x1, int y1, int h1, int w1)
//{
//	this->x1 = x1;
//	this->y1 = y1;
//	this->h1 = y1 + h1;
//	this->w1 = x1 + w1;
//	pParams1_redy = true;
//}
//void Colletent::setPostion2(int x2, int y2,int h2,int w2)
//{
//	this->x2 = x2;
//	this->y2 = y2;
//	this->w2 = x2 + w2;
//	this->h2 = y2 + h2;
//	pParams2_redy = true;
//}
bool Colletent::getColletent(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}
//void Colletent::Colletent_it_P1()
//{
//	pParams1_redy = false;
//}
//void Colletent::Colletent_it_P2()
//{
//	pParams1_redy = false;
//}