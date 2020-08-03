#pragma once
#include <memory>
#include <SDL2/SDL_stdinc.h>

class WindowManager;
class Renderer;

class Game : public std::enable_shared_from_this<Game>
{
public:
	Game();
	~Game();

	bool Initialize();
	void RunLoop();
	void Stop() { isRunning = false; }
	void ResetViewport();

private:
	void ProcessInput();
	void Update();

	std::shared_ptr<WindowManager> windowManager;
	//std::shared_ptr<Renderer> renderer;
	//std::shared_ptr<Scene> scene;
	Uint32 ticksCount;
	bool isRunning;
};

