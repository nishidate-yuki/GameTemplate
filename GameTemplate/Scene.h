#pragma once
#include <vector>
#include <memory>

class Game;

class Scene
{
public:
	Scene();
	~Scene();
	bool Initialize(const float screenWidth, const float screenHeight);
	void Draw();
	void Update(const float deltaTime);

	bool LoadContent();

private:
	std::shared_ptr<Game> game;

	// Environment
	//Sky sky;
	//Camera* camera;
	//DirectionalLight dirLight;
	//PointLight pointLight;

	// Objects
	//std::vector<Model*> models;
};

