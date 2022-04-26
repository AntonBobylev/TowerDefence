#include "SimpleTower.hpp"

SimpleTower::SimpleTower(sf::String textureName, float scale)
	: ShootingEntity(textureName, config::BULLET_TEXTURE_NAME, scale)
{
	this->m_bulletTextureName = config::BULLET_TEXTURE_NAME;
}

void SimpleTower::shoot(sf::Vector2f targetPosition, config::EntitiesContainer& entities)
{
	std::shared_ptr<Bullet> newBullet = std::make_shared<Bullet>(
		this->m_bulletTextureName,
		targetPosition,
		config::BULLET_SPEED,
		config::BULLET_SCALE
	);

	newBullet->setPosition(this->getPosition());
	entities.push_back(newBullet);
	return;
}

void SimpleTower::update(float dt)
{
	ShootingEntity::update(dt);

	
}
