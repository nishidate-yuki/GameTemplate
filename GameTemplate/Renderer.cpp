#include "Renderer.h"

#include <iostream>
#include <GL/glew.h>

#include "WindowManager.h"
#include "Scene.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	printf("Renderer was deleted\n");
}

bool Renderer::Initialize(std::shared_ptr<Game> game,
	std::shared_ptr<WindowManager> windowManager,
	std::shared_ptr<Scene> scene)
{
	if (game && windowManager && scene) {
		this->game = game;
		this->windowManager = windowManager;
		this->scene = scene;
		return true;
	}
	printf("Failed to initialize renderer\n");
	return false;
}

void Renderer::Draw()
{
	// Clear
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	//scene->Draw();

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

	glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

	// ----- “§‰ß•¨‘Ì‚ÌƒŒƒ“ƒ_ƒŠƒ“ƒO -----
	// pass
	// -----------------------------

	// Swap
	windowManager->SwapWindow();
}
