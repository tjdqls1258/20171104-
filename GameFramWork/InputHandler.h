#pragma once
#include "SDL.h"
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	RIGHT = 0,
	MIDDLE = 1,
	LEFT = 2
};


class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	bool getMouseButtonState(int buttonNumber);
	std::vector<bool> m_mouseButtonStates;	//마우스 상태백터(배열같은)
	Vector2D* m_mousePosition;//마우스 이벤트
	Vector2D* getMousePosition();

	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode Key);
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
	const Uint8* m_keystates;
	const Uint8* m_mousestates;
	void onKeyUp();
	void onKeyDown();
	void onMouseButtonUp(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseMove(SDL_Event event);
};

typedef InputHandler TheInputHandler;