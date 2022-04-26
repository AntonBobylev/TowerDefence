#include "PathPoint.hpp"

PathPoint::PathPoint()
	: m_hitted(false)
	, m_coordinate(sf::Vector2f())
{ }

PathPoint::PathPoint(sf::Vector2f coordinate, bool hitted)
	: m_hitted(hitted)
	, m_coordinate(coordinate)
{ }

PathPoint::~PathPoint()
{ }

void PathPoint::setHitted()
{
	this->m_hitted = true;
}

sf::Vector2f PathPoint::getCoordinate() const noexcept
{
	return this->m_coordinate;
}
