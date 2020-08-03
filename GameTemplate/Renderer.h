#pragma once
#include <memory>

class Game;
class WindowManager;
class Scene;

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

