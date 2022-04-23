#pragma once
#include "../Entity/MovingEntity.hpp"

class SimpleEnemy : public MovingEntity {
public:
	SimpleEnemy(sf::String textureName, float scale = 0.5f);
	~SimpleEnemy();
};