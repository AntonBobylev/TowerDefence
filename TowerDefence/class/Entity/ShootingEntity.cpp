#include "ShootingEntity.hpp"

ShootingEntity::ShootingEntity(sf::String textureName, sf::String bulletTextureName, float shootingRadius, float scale)
	: Entity(textureName, scale)
	, m_bulletTextureName(bulletTextureName)
	, m_shootingRadius(shootingRadius)
	, m_shootingAreaShape(shootingRadius, 50u)
	, m_shootingTimer(0.0f)
	, m_shootingDelay(10.0f)
{
	this->setShootingAreaOrigin();
}

ShootingEntity::~ShootingEntity()
{ }

void ShootingEntity::init(sf::String textureName, float scale)
{
	Entity::init(textureName, scale);
	setShootingAreaOrigin();
}

void ShootingEntity::update(float dt, std::vector<std::shared_ptr<Entity>>& entities)
{
	Entity::update(dt, entities);
}

void ShootingEntity::checkCollisions(std::vector<std::shared_ptr<Entity>>& entities, float dt)
{
	// TODO: looks ugly, refactoring needed

	const char* bulletType = typeid(Bullet).name();
	const char* thisType = typeid(*this).name();
	
	sf::FloatRect areaRect = this->m_shootingAreaShape.getGlobalBounds();

	for (uint16_t i = 0; i < entities.size(); i++) {
		const char* entityType = typeid(*entities[i]).name();
		
		if (entityType != bulletType && entityType != thisType) {
			sf::Vector2f entityPos = entities[i]->getPosition();

			if (areaRect.contains(entityPos)) {
				if (this->m_shootingTimer >= this->m_shootingDelay) {
					this->shoot(entities[i]->getPosition(), entities);
					this->m_shootingTimer = 0.0f;
				} else {
					this->m_shootingTimer += dt * 10.0f;
				}
			}
		}
	}
}

void ShootingEntity::setShootingAreaOrigin()
{
	this->m_shootingAreaShape.setOrigin(
		this->m_shootingRadius,
		this->m_shootingRadius
	);
}

void ShootingEntity::render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(this->m_shootingAreaShape);
	Entity::render(window);
}

void ShootingEntity::setPosition(sf::Vector2f position)
{
	Entity::setPosition(position);
	this->m_shootingAreaShape.setPosition(position);
}
