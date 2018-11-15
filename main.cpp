#include <SDL.h>
#include "Game.h"

Game* g_game = 0;

int main(int argc, char* args[])
{
	g_game = new Game();
	g_game->init("챕터 1", 100, 100, 680, 480, false);//windows창 생성
	while (g_game->running())
	{
		g_game->handleEvents();//사용자 입력
		g_game->update();//정보 업데이트
		g_game->render();//정보를 바탕으로 그려줌
	}
	g_game->clean();
	return 0;
}