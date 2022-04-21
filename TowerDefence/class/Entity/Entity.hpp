#pragma once
#include "SFML/Graphics.hpp"

class Entity {
public:
	Entity() = delete;
	Entity(sf::String textureName);
	~Entity();

public:
	void setPosition(sf::Vector2f position);

private:
	void init(sf::String textureName);

public:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};