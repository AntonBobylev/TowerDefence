#include "Entity.hpp"

Entity::Entity(sf::String textureName, float scale)
	: m_needToBeRemoved(false)
{
	this->init(textureName, scale);
}

Entity::~Entity()
{
}

void Entity::setPosition(sf::Vector2f position)
{
	this->m_sprite.setPosition(position);
}

sf::Vector2f Entity::getPosition() const noexcept
{
	return this->m_sprite.getPosition();
}

void Entity::render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(this->m_sprite);
}

bool Entity::removeRequired() const noexcept
{
	return this->m_needToBeRemoved;
}

void Entity::checkWindowBounds()
{
	if (this->getPosition().x > config::WINDOW_WIDTH + 20.0f
		|| this->getPosition().x < -20.0f
		|| this->getPosition().y > config::WINDOW_HEIGHT + 20.0f
		|| this->getPosition().y < -20.0f) {
		this->m_needToBeRemoved = true;
	}
}

sf::Vector2i Entity::getSpriteSize() const noexcept
{
	sf::IntRect textureRect = this->m_sprite.getTextureRect();
	return { textureRect.width, textureRect.height};
}

void Entity::update(float dt, std::vector<std::shared_ptr<Entity>>& entities)
{
	if (this->m_needToBeRemoved) {
		return;
	}

	this->checkCollisions(entities, dt);
	this->checkWindowBounds();
	this->animate(dt);
}

void Entity::animate(float dt)
{
}

void Entity::init(sf::String textureName, float scale)
{
	this->m_texture.loadFromFile(textureName);
	this->m_sprite.setTexture(this->m_texture);

	this->m_scale = scale;
	this->m_sprite.setScale(this->m_scale, this->m_scale);

	this->setSpriteOrigin();
}

void Entity::checkCollisions(std::vector<std::shared_ptr<Entity>>& entities, float dt)
{
}

void Entity::setSpriteOrigin()
{
	// set the center point in the sprite center
	float textureWidth = static_cast<float>(this->m_sprite.getTextureRect().width) * this->m_scale;
	float textureHeight = static_cast<float>(this->m_sprite.getTextureRect().height) * this->m_scale;
	this->m_sprite.setOrigin(
		textureWidth / 2,
		textureHeight / 2
	);
}
