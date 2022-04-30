#pragma once
#include "MovingEntity.hpp"

class EnemyEntity : public MovingEntity {
public:
	EnemyEntity() = delete;
	EnemyEntity(const EnemyEntity&) = delete;
	EnemyEntity(sf::String textureName, sf::Vector2f target, float speed, float scale = 0.5f);
	~EnemyEntity() {};
};