#pragma once
#include "../MovingEntity.hpp"

class Bullet : public Entity {
public:
	Bullet() = delete;
	Bullet(sf::String textureName, sf::Vector2f targetPosition, float bulletSpeed = 0.1f, float scale = 0.5f);
	~Bullet();

private:
	void update(float dt);
	void hittedTarget();
	sf::Vector2f normalize();
	sf::Vector2f calculateDestinationPoint(float dt);

private:
	sf::Vector2f m_targetPosition;
	float m_speed;
};