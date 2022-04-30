#pragma once
#include "../Entity/EnemyEntity.hpp"

class SimpleEnemy : public EnemyEntity{
public:
	SimpleEnemy() = delete;
	SimpleEnemy(sf::String textureName, sf::Vector2f target, float speed, float scale = 0.5f);
	~SimpleEnemy();
};