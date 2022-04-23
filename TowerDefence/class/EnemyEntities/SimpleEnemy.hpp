#pragma once
#include "../Entity/MovingEntity.hpp"

class SimpleEnemy : public MovingEntity {
public:
	SimpleEnemy() = delete;
	SimpleEnemy(sf::String textureName, sf::Vector2f target, float speed, float scale = 0.5f);
	~SimpleEnemy();
};