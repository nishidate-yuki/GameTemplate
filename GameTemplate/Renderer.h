#pragma once
#include <memory>
#include <SDL2/SDL.h>

#include "WindowManager.h"
#include "Scene.h"

class Game;

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool Initialize(std::shared_ptr<Game> game,
		std::shared_ptr<WindowManager> windowManager,
		std::shared_ptr<Scene> scene);

	void Draw();

private:
	std::shared_ptr<Game> game;
	std::shared_ptr<WindowManager> windowManager;
	std::shared_ptr<Scene> scene;
	//Camera* camera;

	float screenWidth;
	float screenHeight;
};

