#pragma once
#include "GameObject.h"

class LoaderParams
{
private:
	int m_x;
	int m_y;
	int m_widht;
	int m_height;
	std::string m_textureID;
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID) : m_x(x), m_y(y),
		m_widht(width), m_height(height), m_textureID(textureID)
	{

	}
};