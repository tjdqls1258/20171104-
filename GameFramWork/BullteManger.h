#pragma once
#ifndef BULLTEMANGER_H
#define BULLTEMANGER_H

#include <vector>
#include "Bullte.h"
class BullteManger
{
private:
	static BullteManger* s_pInstance;
public:
	static BullteManger* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new BullteManger();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void instance_bullte(int x, int y, int speed);
	void draw();
	void update();
	void clean();
	void delete_Bullte(int i);
	std::vector<GameObject*> m_bullte;
};

#endif // BULLTEMANGER_H