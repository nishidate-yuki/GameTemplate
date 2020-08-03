#pragma once
#include <GL/glew.h>
#include <SDL2/SDL_stdinc.h>

class WindowManager
{
public:
	// OpenGLの初期化の関係でコンストラクタではなくInitialize()を使用する
	WindowManager();
	~WindowManager();

	bool Initialize(float screenWidth, float screenHeight);
	void SwapWindow();
	void ResetViewport();
	auto GetScreenWidth() const { return screenWidth; }
	auto GetScreenHeight() const { return screenHeight; }

private:
	class SDL_Window* window;
	//SDL_GLContext context;
	float screenWidth;
	float screenHeight;
};

