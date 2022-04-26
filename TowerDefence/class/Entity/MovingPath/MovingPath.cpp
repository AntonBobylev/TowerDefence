#include "MovingPath.hpp"

MovingPath::MovingPath()
	: m_pointsContainer(std::vector<PathPoint>())
	, m_pointsIndex(0u)
	, m_pathPassed(false)
{ 
	this->fillPointsContainer();
}

MovingPath::~MovingPath()
{ }

void MovingPath::fillPointsContainer()
{
	if (this->m_pointsContainer.size() > 0u) {
		return;
	}

	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(20.0f, 50.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(800.0f, 50.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(800.0f, 150.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(20.0f, 150.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(20.0f, 250.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(800.0f, 250.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(800.0f, 350.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(20.0f, 350.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(20.0f, 450.0f) });
	this->m_pointsContainer.push_back(PathPoint{ sf::Vector2f(800.0f, 450.0f) });
}

void MovingPath::setPointHitted()
{
	if (this->m_pathPassed) {
		return;
	}

	if (this->m_pointsIndex > this->m_pointsContainer.size() - 1u) {
		this->m_pathPassed = true;
	}

	this->m_pointsContainer[this->m_pointsIndex].setHitted();
	this->m_pointsIndex++;
}

std::vector<PathPoint> MovingPath::getPoints() const noexcept
{
	return this->m_pointsContainer;
}

bool MovingPath::isPathPassed() const noexcept
{
	return this->m_pathPassed;
}

sf::Vector2f MovingPath::getNextPoint()
{
	if (this->m_pointsIndex >= this->m_pointsContainer.size()) {
		this->m_pathPassed = true;
		return config::OUT_THE_MAP_POINT;
	}
	return this->m_pointsContainer[this->m_pointsIndex].getCoordinate();
}
