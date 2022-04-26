#pragma once
#include <SFML/Graphics.hpp>

class PathPoint {
public:
	PathPoint();
	PathPoint(sf::Vector2f coordinate, bool hitted = false);
	~PathPoint();

public:
	void setHitted();
	sf::Vector2f getCoordinate() const noexcept;

private:
	bool m_hitted;
	sf::Vector2f m_coordinate;
};