#pragma once
#include "Entity.hpp"
#include "MovingPath/MovingPath.hpp"

class MovingEntity : public Entity {
public:
	MovingEntity() = delete;
	MovingEntity(sf::String textureName, sf::Vector2f target, float speed, float scale = 0.5f);
	~MovingEntity();

public:
	virtual void update(float dt, std::vector<std::shared_ptr<Entity>>& entities);
	sf::Vector2f calculateDestinationPoint(float dt); // Calculates destination point for the current frame
	void hittedTarget();
	sf::Vector2f normalize();

public:
	MovingPath m_path;
	sf::Vector2f m_targetPosition;
	float m_speed;
};