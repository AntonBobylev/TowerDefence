#pragma once
#include "../Entity/ShootingEntity.hpp"

class SimpleTower : public ShootingEntity {
public:
	SimpleTower(sf::String textureName, float scale = 0.5f);
	~SimpleTower() {};

public:
	void shoot(sf::Vector2f targetPosition, std::vector<std::shared_ptr<Entity>>& entities);
};