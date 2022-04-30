#pragma once
#include "Entity.hpp"
#include "Bullet/Bullet.hpp"
#include "../EnemyEntities/SimpleEnemy.hpp"

class ShootingEntity : public Entity {
public:
	ShootingEntity() = delete;
	ShootingEntity(sf::String textureName, sf::String bulletTextureName, float shootingRadius = 150.0f, float scale = 0.5f);
	~ShootingEntity();

public:
	void init(sf::String textureName, float scale);
	void update(float dt, std::vector<std::shared_ptr<Entity>>& entities);
	void checkCollisions(std::vector<std::shared_ptr<Entity>>& entities, float dt);

	virtual void shoot(sf::Vector2f targetPosition, std::vector<std::shared_ptr<Entity>>& entities) = 0;

	void setShootingAreaOrigin();
	void render(std::shared_ptr<sf::RenderWindow> window);
	void setPosition(sf::Vector2f position);

public:
	sf::String m_bulletTextureName;
	sf::CircleShape m_shootingAreaShape;
	float m_shootingRadius;

	float m_shootingDelay;
	float m_shootingTimer;
};