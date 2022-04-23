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
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const noexcept;
	void render(std::shared_ptr<sf::RenderWindow> window);
	bool removeRequired() const noexcept;
	void checkWindowBounds();

public:
	virtual void update(float dt);
	virtual void animate(float dt);

private:
	void init(sf::String textureName, float scale);
	void setSpriteOrigin();

public:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_scale;
	bool m_needToBeRemoved;
};