#include "Game.h"
#include <SDL2/SDL.h>
//#include "Scene.h"

Game::Game()
	: isRunning(true)
{
}

Game::~Game()
{
}

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	//windowManager = std::make_shared<WindowManager>();
	//renderer = std::make_shared<Renderer>();

	float screenWidth = 1024.0f;
	float screenHeight = 768.0f;

	// Initialize vars
	bool success = true;
	//success &= windowManager->Initialize(screenWidth, screenHeight);
	//success &= renderer->Initialize(shared_from_this(), windowManager, scene);
	//success &= scene->Initialize(screenWidth, screenHeight);
	if (!success) {
		SDL_Log("Failed to initialize game");
		return false;
	}

	ticksCount = SDL_GetTicks();

	return true;
}

void Game::RunLoop()
{
	while (isRunning) {
		ProcessInput();
		Update();
		//renderer->Draw();
	}
}

void Game::ProcessInput()
{
}

void Game::Update()
{
	// 16msŒo‚Â‚Ü‚Å‘Ò‚Â
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16)) {
		// pass
	}
	float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;
	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;
	}
	ticksCount = SDL_GetTicks();

	//scene.Update(deltaTime);
}

