#include "ShootingEntity.hpp"

ShootingEntity::ShootingEntity(sf::String textureName, sf::String bulletTextureName, float scale)
	: Entity(textureName, scale)
	, m_bulletTextureName(bulletTextureName)
{ }

ShootingEntity::~ShootingEntity()
{ }
