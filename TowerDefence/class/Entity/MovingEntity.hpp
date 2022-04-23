#pragma once
#include "Entity.hpp"

class MovingEntity : public Entity {
public:
	MovingEntity(sf::String textureName, sf::Vector2f target, float speed, float scale = 0.5f);
	~MovingEntity();

public:
	virtual void update(float dt);
	sf::Vector2f calculateDestinationPoint(float dt); // Calculates destination point for current frame
	void hittedTarget();
	sf::Vector2f normalize(sf::Vector2f target, sf::Vector2f current);

public:
	sf::Vector2f m_targetPosition;
	float m_speed;
};