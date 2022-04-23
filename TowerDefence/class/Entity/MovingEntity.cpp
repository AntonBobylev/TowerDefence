#include "MovingEntity.hpp"

MovingEntity::MovingEntity(sf::String textureName, float scale)
	: Entity(textureName, scale)
{
}

MovingEntity::~MovingEntity()
{ }

void MovingEntity::update(float dt)
{
}
