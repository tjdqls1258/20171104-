#include "BullteManger.h"
#include"Colletent.h"
BullteManger* BullteManger::s_pInstance = nullptr;

void BullteManger::instance_bullte(int x, int y, int speed)
{
	m_bullte.push_back(new Bullte(new LoaderParams(x, y, 32, 32, "bullte"), speed));
}

void BullteManger::draw()
{
	for (int i = 0; i < m_bullte.size(); i++)
	{
		m_bullte[i]->draw();
	}
}

void BullteManger::update()
{
	for (int i = 0; i < m_bullte.size(); i++)
	{
		m_bullte[i]->update();
		if (m_bullte[i]->returncoll())
		{
			delete_Bullte(i);
			//Colletent::Instance()->Colletent_it_P1();
		}
	}
	
}

void BullteManger::clean()
{
	for (int i = 0; i < m_bullte.size(); i++)
	{
		m_bullte[i]->clean();
	}
	m_bullte.clear();
}
void BullteManger::delete_Bullte(int i)
{
	m_bullte.erase(m_bullte.begin() + i);
}