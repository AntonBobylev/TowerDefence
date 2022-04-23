#include "SimpleEnemy.hpp"

SimpleEnemy::SimpleEnemy(sf::String textureName, sf::Vector2f target, float speed, float scale)
	: MovingEntity(textureName, target, speed, scale)
{
}

SimpleEnemy::~SimpleEnemy()
{
}
