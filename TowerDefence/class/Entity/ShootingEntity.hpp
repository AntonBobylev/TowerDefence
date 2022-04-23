#pragma once
#include "Entity.hpp"
#include "Bullet/Bullet.hpp"

class ShootingEntity : public Entity {
public:
	ShootingEntity() = delete;
	ShootingEntity(sf::String textureName, sf::String bulletTextureName, float scale = 0.5f);
	~ShootingEntity();

public:
	virtual void shoot(sf::Vector2f targetPosition, config::EntitiesContainer& entities) = 0;

public:
	sf::String m_bulletTextureName;
};