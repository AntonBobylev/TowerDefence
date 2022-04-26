#pragma once
#include "SFML/Graphics.hpp"
#include "PathPoint.hpp"
#include "../../GameManager/config.hpp"

class MovingPath {
public:
	MovingPath();
	MovingPath(const MovingPath&) = delete;
	~MovingPath();

private:
	void fillPointsContainer();

public:
	void setPointHitted();
	std::vector<PathPoint> getPoints() const noexcept;
	bool isPathPassed() const noexcept;
	sf::Vector2f getNextPoint();

private:
	std::vector<PathPoint> m_pointsContainer;
	uint8_t m_pointsIndex;
	bool m_pathPassed;
};