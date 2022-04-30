#pragma once
#include "../Entity/ShootingEntity.hpp"

class SimpleTower : public ShootingEntity {
public:
	SimpleTower() = delete;
	SimpleTower(sf::String textureName, sf::String bulletTextureName, float shootingRadius = 150.0f, float scale = 0.5f);
	~SimpleTower() {};

public:
	void shoot(sf::Vector2f targetPosition, std::vector<std::shared_ptr<Entity>>& entities);

private:
	void update(float dt, std::vector<std::shared_ptr<Entity>>& entities);
};