#include "Application.hpp"
#include "../PlayerEntities/SimpleTower.hpp"

Application::Application()
	: m_window(config::WINDOW_WIDTH, config::WINDOW_HEIGHT, "Tower Defence: The Game")
	, m_entities()
{
	init();
}

Application::~Application()
{
}

void Application::init()
{ }

void Application::addEntityToContainer(Entity entity)
{
	this->m_entities.push_back(entity);
}

int Application::mainLoop()
{
	SimpleTower tower{ "resources/tower_texture.png" };
	tower.setPosition(sf::Vector2f(config::WINDOW_WIDTH / 2, config::WINDOW_HEIGHT / 2));
	this->addEntityToContainer(tower);
	while (this->m_window.isWindowOpened()) {
		this->m_window.pollEvents();

		this->m_window.clearScreen();
		this->m_window.renderEntities(this->m_entities);
		this->m_window.displayScreen();
	}

	return 0;
}
