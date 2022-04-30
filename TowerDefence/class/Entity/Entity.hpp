#pragma once
#include "SFML/Graphics.hpp"
#include "../GameManager/config.hpp"

class Entity {
public:
	Entity() = delete;
	Entity(const Entity&) = delete;
	Entity(sf::String textureName, float scale = 0.5f);
	~Entity();

public:
	virtual void init(sf::String textureName, float scale);
	virtual void checkCollisions(std::vector<std::shared_ptr<Entity>>& entities, float dt);
	virtual void render(std::shared_ptr<sf::RenderWindow> window);
	
	virtual void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const noexcept;
	
	sf::Vector2i getSpriteSize() const noexcept;


	bool removeRequired() const noexcept;
	void checkWindowBounds();

public:
	virtual void update(float dt, std::vector<std::shared_ptr<Entity>>& entities);
	virtual void animate(float dt);

private:
	void setSpriteOrigin();

public:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_scale;
	bool m_needToBeRemoved;
};