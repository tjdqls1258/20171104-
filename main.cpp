#include <SDL.h>
#include "Game.h"

Game* g_game = 0;

int main(int argc, char* args[])
{
	g_game = new Game();
	g_game->init("é�� 1", 100, 100, 680, 480, false);//windowsâ ����
	while (g_game->running())
	{
		g_game->handleEvents();//����� �Է�
		g_game->update();//���� ������Ʈ
		g_game->render();//������ �������� �׷���
	}
	g_game->clean();
	return 0;
}