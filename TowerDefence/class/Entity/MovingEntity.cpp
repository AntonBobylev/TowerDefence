#include "MovingEntity.hpp"

MovingEntity::MovingEntity(sf::String textureName, sf::Vector2f target, float speed, float scale)
	: Entity(textureName, scale)
	, m_speed(speed)
	, m_path()
{
	this->m_targetPosition = this->m_path.getPoints()[0].getCoordinate();
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
	if (this->m_path.isPathPassed()) {
		this->m_needToBeRemoved = true;
		this->m_sprite.setPosition(config::OUT_THE_MAP_POINT);
	}

	sf::Vector2i targetPosition = static_cast<sf::Vector2i>(this->m_targetPosition);
	sf::Vector2i currentPosition = static_cast<sf::Vector2i>(this->getPosition());

	sf::IntRect targetRect{ 
		sf::Vector2i(targetPosition.x - config::ENTITY_LOCAL_RECT.x / 2, 
					 targetPosition.y - config::ENTITY_LOCAL_RECT.y / 2),
		config::ENTITY_LOCAL_RECT };
	
	if (targetRect.contains(currentPosition)) {
		this->m_path.setPointHitted();
		this->m_targetPosition = this->m_path.getNextPoint();
	}
}

sf::Vector2f MovingEntity::normalize()
{
	sf::Vector2f currentPosition = this->getPosition();
	sf::Vector2f source = this->m_targetPosition - currentPosition;
	
	float length = sqrt((source.x * source.x) + (source.y * source.y));

	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);

	return source;
}