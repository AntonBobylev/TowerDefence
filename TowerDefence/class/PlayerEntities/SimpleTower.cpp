#include "SimpleTower.hpp"

SimpleTower::SimpleTower(sf::String textureName, float scale)
	: ShootingEntity(textureName, "resources/bullet.png", scale)
{
	this->m_bulletTextureName = "resources/bullet.png";
}

void SimpleTower::shoot(sf::Vector2f targetPosition, std::vector<std::shared_ptr<Entity>>& entities)
{
	std::shared_ptr<Bullet> newBullet = std::make_shared<Bullet>(this->m_bulletTextureName, targetPosition, 0.25f);
	newBullet->setPosition(this->getPosition()); // TODO: Remove it, it's just for test
	entities.push_back(newBullet);
	return;
}
