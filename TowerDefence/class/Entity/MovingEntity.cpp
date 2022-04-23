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
	Entity::update(dt);

	this->hittedTarget();

	this->m_sprite.move(this->calculateDestinationPoint(dt));
}

sf::Vector2f MovingEntity::calculateDestinationPoint(float dt)
{
	sf::Vector2f destinationPoint = normalize();

	destinationPoint.x *= this->m_speed * dt;
	destinationPoint.y *= this->m_speed * dt;

	return destinationPoint;
}

void MovingEntity::hittedTarget()
{
	sf::IntRect targetRect{ static_cast<sf::Vector2i>(this->m_targetPosition), config::ENTITY_LOCAL_RECT };
	if (targetRect.contains(static_cast<sf::Vector2i>(this->getPosition()))) {
		this->m_needToBeRemoved = true;
		this->m_sprite.setPosition(config::OUT_THE_MAP_POINT);
	}
}

sf::Vector2f MovingEntity::normalize()
{
	sf::Vector2f currentPosition = this->getPosition();
	int8_t xSign = currentPosition.x > this->m_targetPosition.x ? -1 : 1;
	int8_t ySign = currentPosition.y > this->m_targetPosition.y ? -1 : 1;

	float SlopeX = this->m_targetPosition.x - currentPosition.x;
	float SlopeY = this->m_targetPosition.y - currentPosition.y;

	sf::Vector2f normal;

	if ((SlopeY == 1) || (SlopeY == -1)) {
		normal.y = SlopeY;
		normal.x = SlopeX;
	} else {
		normal.y = xSign * (SlopeY / SlopeY);
		normal.x = ySign * (SlopeX / SlopeY);
	}

	return normal;
}