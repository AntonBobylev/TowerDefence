#include "Bullet.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

Bullet::Bullet(sf::String textureName, sf::Vector2f targetPosition, float bulletSpeed, float scale)
	: Entity(textureName, scale)
	, m_targetPosition(targetPosition)
	, m_bulletSpeed(bulletSpeed)
{
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	this->checkWindowBounds();

	if (this->m_needToBeRemoved) {
		return;
	}

	this->hittedTarget();

	this->m_sprite.move(
		this->calculateDestinationPoint(dt)
	);
}

sf::Vector2f normalize(sf::Vector2f Target, sf::Vector2f Current)
{
	sf::Vector2f _Normal;
	float SlopeX = Target.x - Current.x;
	float SlopeY = Target.y - Current.y;
	if ((SlopeY == 1) || (SlopeY == -1))
	{
		_Normal.y = SlopeY;
		_Normal.x = SlopeX;
	}
	else
	{
		_Normal.y = -(SlopeY / SlopeY);
		_Normal.x = -(SlopeX / SlopeY);
	}
	return _Normal;
}

sf::Vector2f Bullet::calculateDestinationPoint(float dt)
{
	sf::Vector2f bulletPosition = this->getPosition();

	sf::Vector2f destinationPoint = normalize(this->m_targetPosition, bulletPosition);

	destinationPoint.x *= this->m_bulletSpeed * dt;
	destinationPoint.y *= this->m_bulletSpeed * dt;

	return destinationPoint;
}

void Bullet::hittedTarget()
{
	sf::Vector2f bulletPosition = this->getPosition();
	bool atTheX = bulletPosition.x == this->m_targetPosition.x;
	bool atTheY = bulletPosition.y == this->m_targetPosition.y;
	if (atTheX && atTheY) {
		this->m_needToBeRemoved = true;

		sf::Vector2f outTheMap{ 10000.0f, 10000.0f };
		this->m_sprite.setPosition(outTheMap);
	}
}
