#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/Entity.hpp"

// Entity class already exists
class Entity;

namespace config {
	typedef std::vector<std::shared_ptr<Entity>> EntitiesContainer;

	const int16_t WINDOW_WIDTH = 1280;
	const int16_t WINDOW_HEIGHT = 720;

	const float BULLET_SPEED = 1.25f;
	const float BULLET_SCALE = 0.25f;

	const float SIMPLE_TOWER_SCALE = 0.5f;

	const float SIMPLE_ENEMY_SCALE = 0.5f;
	const float SIMPLE_ENEMY_SPEED = 2.05f;

	const sf::Vector2f OUT_THE_MAP_POINT { 10000.0f,10000.0f };
	
	const sf::Vector2i ENTITY_LOCAL_RECT { 5, 5 };

	const sf::String RESOURCES_FOLDER_NAME = "resources";
	const sf::String FOLDER_SEPARATOR = "/";

	const sf::String SIMPLE_ENEMY_TEXTURE_NAME = RESOURCES_FOLDER_NAME + FOLDER_SEPARATOR + "simple_enemy.png";
	const sf::String SIMPLE_TOWER_TEXTURE_NAME = RESOURCES_FOLDER_NAME + FOLDER_SEPARATOR + "simple_tower.png";
	const sf::String BULLET_TEXTURE_NAME = RESOURCES_FOLDER_NAME + FOLDER_SEPARATOR + "bullet.png";
}