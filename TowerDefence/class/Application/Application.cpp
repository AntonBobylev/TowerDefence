#include "Application.hpp"
#include "../PlayerEntities/SimpleTower.hpp"
#include "../EnemyEntities/SimpleEnemy.hpp"
#include <iostream>

Application::Application()
	: m_window(std::make_shared<SFMLWindow>(config::WINDOW_WIDTH, config::WINDOW_HEIGHT, "Tower Defence: The Game"))
	, m_entities()
{
	init();
}

Application::~Application()
{
}

void Application::init()
{ }

void Application::addEntityToContainer(std::shared_ptr<Entity> entity)
{
	this->m_entities.push_back(entity);
}

void Application::renderEntities()
{
	for (unsigned int i = 0u; i < this->m_entities.size(); i++) {
		this->m_entities[i]->render(this->m_window->getWindow());
	}
}

void Application::updateEntities(float dt)
{
	for (unsigned int i = 0u; i < this->m_entities.size(); i++) {
		if (this->m_entities[i]->removeRequired()) {
			this->m_entities.erase(this->m_entities.begin() + i);
		} else {
			this->m_entities[i]->update(dt);
		}
		
	}
}

int Application::mainLoop()
{
	std::shared_ptr<SimpleTower> tower = std::make_shared<SimpleTower>(config::SIMPLE_TOWER_TEXTURE_NAME);
	tower->setPosition(sf::Vector2f(config::WINDOW_WIDTH / 2, config::WINDOW_HEIGHT / 2));
	this->addEntityToContainer(tower);
	tower->shoot(sf::Vector2f(50.0f, 50.0f), this->m_entities);

	std::shared_ptr<SimpleEnemy> enemy = std::make_shared<SimpleEnemy>(
		config::SIMPLE_ENEMY_TEXTURE_NAME, 
		sf::Vector2f(900.0f, 600.0f), 
		config::SIMPLE_ENEMY_SPEED, 
		config::SIMPLE_ENEMY_SCALE
	);

	enemy->setPosition(sf::Vector2f(600,200));
	this->addEntityToContainer(enemy);

	sf::Clock deltaClock;
	while (this->m_window->isWindowOpened()) {
		this->m_window->pollEvents();

		float dt = static_cast<float>(deltaClock.getElapsedTime().asMilliseconds());
		deltaClock.restart();

		std::cout << this->m_entities.size() << std::endl;;

		this->m_window->clearScreen();
		this->updateEntities(dt);
		this->renderEntities();
		this->m_window->displayScreen();
	}

	return 0;
}
