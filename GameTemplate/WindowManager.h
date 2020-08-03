#pragma once
#include <SDL2/SDL.h>

class WindowManager
{
public:
	// OpenGL�̏������̊֌W�ŃR���X�g���N�^�ł͂Ȃ�Initialize()���g�p����
	WindowManager();
	~WindowManager();

	bool Initialize(float screenWidth, float screenHeight);
	void SwapWindow();
	void ResetViewport();
	auto GetScreenWidth() const { return screenWidth; }
	auto GetScreenHeight() const { return screenHeight; }

private:
	SDL_Window* window;
	SDL_GLContext context;
	float screenWidth;
	float screenHeight;
};

