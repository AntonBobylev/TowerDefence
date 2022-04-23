#include "Bullet.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

Bullet::Bullet(sf::String textureName, sf::Vector2f targetPosition, float bulletSpeed, float scale)
	: MovingEntity(textureName, targetPosition, bulletSpeed, scale)
{ }

Bullet::~Bullet()
{
}
