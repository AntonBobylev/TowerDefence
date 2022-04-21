#include "Entity.hpp"

Entity::Entity(sf::String textureName)
{
	this->init(textureName);
}

Entity::~Entity()
{
}

void Entity::setPosition(sf::Vector2f position)
{
	this->m_sprite.setPosition(position);
}

void Entity::init(sf::String textureName)
{
	this->m_texture.loadFromFile(textureName);
	this->m_sprite.setTexture(this->m_texture);
}
