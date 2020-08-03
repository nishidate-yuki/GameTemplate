#include "WindowManager.h"

#include <iostream>
#include <SDL2/SDL.h>

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
	SDL_DestroyWindow(window);
	//SDL_GL_DeleteContext(context);
	printf("WindowManager was deleted\n");
}

bool WindowManager::Initialize(float screenWidth, float screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

	// Core profile を使用する
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	// Version 4.3
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	// Color buffer の設定
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	// ダブルバッファリングを有効にする
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	// アンチエイリアシング
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
	// ハードウェア・アクセラレーションを使用する
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	// Create OpenGL window
	window = SDL_CreateWindow("SDL Window", 100, 100,
		static_cast<int>(screenWidth), static_cast<int>(screenHeight), SDL_WINDOW_OPENGL);
	if (!window) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	// Create OpenGL context
	//context = SDL_GL_CreateContext(window);

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		SDL_Log("Failed to initialize GLEW.");
		return false;
	}
	glGetError(); // Clear error

	// デプス値が現在値「以下」であればパスする(skyboxのためのトリック)
	glDepthFunc(GL_LEQUAL);
	// キューブマップをシームレスにする
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

	return true;
}

inline void WindowManager::SwapWindow() { SDL_GL_SwapWindow(window); }

inline void WindowManager::ResetViewport() { glViewport(0, 0, screenWidth, screenHeight); }
