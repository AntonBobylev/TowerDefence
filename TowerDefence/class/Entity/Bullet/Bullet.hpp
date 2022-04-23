#pragma once
#include "../MovingEntity.hpp"

class Bullet : public MovingEntity {
public:
	Bullet() = delete;
	Bullet(sf::String textureName, sf::Vector2f targetPosition, float bulletSpeed = 0.1f, float scale = 0.5f);
	~Bullet();
};