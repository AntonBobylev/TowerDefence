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
	void addEntityToContainer(Entity entity);

private:
	SFMLWindow m_window;
	std::vector<Entity> m_entities;
};