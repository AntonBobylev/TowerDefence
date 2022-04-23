#include "MovingEntity.hpp"

MovingEntity::MovingEntity(sf::String textureName, sf::Vector2f target, float speed, float scale)
	: Entity(textureName, scale)
	, m_targetPosition(target)
	, m_speed(speed)
{
}

MovingEntity::~MovingEntity()
{ }

void MovingEntity::update(float dt)
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

sf::Vector2f MovingEntity::calculateDestinationPoint(float dt)
{
	sf::Vector2f currentPosition = this->getPosition();
	sf::Vector2f destinationPoint = normalize(this->m_targetPosition, currentPosition);

	destinationPoint.x *= this->m_speed * dt;
	destinationPoint.y *= this->m_speed * dt;

	return destinationPoint;
}

void MovingEntity::hittedTarget()
{
	sf::IntRect targetRect{ static_cast<sf::Vector2i>(this->m_targetPosition), sf::Vector2i(5, 5) };
	if (targetRect.contains(static_cast<sf::Vector2i>(this->getPosition()))) {
		this->m_needToBeRemoved = true;

		sf::Vector2f outTheMap{ 10000.0f, 10000.0f };
		this->m_sprite.setPosition(outTheMap);
	}
}

sf::Vector2f MovingEntity::normalize(sf::Vector2f target, sf::Vector2f current)
{
	sf::Vector2f normal;

	int8_t xSign = current.x > target.x ? -1 : 1;
	int8_t ySign = current.y > target.y ? -1 : 1;

	float SlopeX = target.x - current.x;
	float SlopeY = target.y - current.y;

	if ((SlopeY == 1) || (SlopeY == -1))
	{
		normal.y = SlopeY;
		normal.x = SlopeX;
	}
	else
	{
		normal.y = xSign * (SlopeY / SlopeY);
		normal.x = ySign * (SlopeX / SlopeY);
	}
	return normal;
}