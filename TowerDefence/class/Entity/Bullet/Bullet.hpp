#pragma once
#include "../Entity.hpp"

class Bullet : public Entity {
public:
	Bullet() = delete;
	Bullet(sf::String textureName, sf::Vector2f targetPosition, float bulletSpeed = 0.1f, float scale = 0.5f);
	~Bullet();

private:
	void update(float dt);
	sf::Vector2f calculateDestinationPoint(float dt); // Calculates destination point for current frame
	void hittedTarget();

private:
	sf::Vector2f m_targetPosition;
	float m_bulletSpeed;
};