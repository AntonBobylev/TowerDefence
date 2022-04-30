#include "EnemyEntity.hpp"

EnemyEntity::EnemyEntity(sf::String textureName, sf::Vector2f target, float speed, float scale)
	: MovingEntity(textureName, target, speed, scale)
{ }
