#pragma once
#include"SDLGameObject.h"
class Colletent
{
private:
	Colletent() { ; }
	static Colletent* s_pInstance;
	bool pParams1_redy = false;
	bool pParams2_redy = false;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, h1 = 0, h2 = 0, w1 = 0, w2 = 0;
public:
	static Colletent* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Colletent();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool getColletent(SDLGameObject* p1, SDLGameObject* p2);
	//void setPostion1(int x2, int y2, int h2, int w2);
	//void setPostion2(int x, int y, int h, int w);
	//void Colletent_it_P1();
	//void Colletent_it_P2();
};

