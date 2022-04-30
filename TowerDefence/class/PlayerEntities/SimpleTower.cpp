#include "SimpleTower.hpp"

SimpleTower::SimpleTower(sf::String textureName, sf::String bulletTextureName, float shootingRadius, float scale)
	: ShootingEntity(textureName, config::BULLET_TEXTURE_NAME, shootingRadius, scale)
{
	this->m_bulletTextureName = config::BULLET_TEXTURE_NAME;
	this->m_shootingRadius = 150.0f;
}

void SimpleTower::shoot(sf::Vector2f targetPosition, std::vector<std::shared_ptr<Entity>>& entities)
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

void SimpleTower::update(float dt, std::vector<std::shared_ptr<Entity>>& entities)
{
	ShootingEntity::update(dt, entities);
	
}
