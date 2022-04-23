#pragma once
#include "Entity.hpp"

class MovingEntity : public Entity {
public:
	MovingEntity(sf::String textureName, float scale = 0.5f);
	~MovingEntity();

public:
	void update(float dt);
};