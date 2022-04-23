#pragma once
#include "../GameManager/config.hpp"
#include "../Entity/Entity.hpp"
#include "../SFMLWindow/SFMLWindow.hpp"

class Application {

public:
	Application();
	~Application();

public:
	int mainLoop();

private:
	void init();

private:
	void addEntityToContainer(std::shared_ptr<Entity> entity);
	void renderEntities();
	void updateEntities(float dt);

private:
	std::shared_ptr<SFMLWindow> m_window;
	config::EntitiesContainer m_entities;
};