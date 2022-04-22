#include "SFMLWindow.hpp"
//#include <iostream>

SFMLWindow::SFMLWindow(const int16_t width, const int16_t height, const char* appName)
	: m_windowWidth(width)
	, m_windowHeight(height)
	, m_window(std::make_shared<sf::RenderWindow>(
		sf::VideoMode(width, height),
		appName, sf::Style::Close
		)
	)
	, m_event(std::make_shared<sf::Event>())
{ 
	
}

SFMLWindow::~SFMLWindow()
{ }

void SFMLWindow::pollEvents()
{
	while (this->m_window->pollEvent(*this->m_event)) {
		this->pollExitEvent();
		this->pollKeyboardEvents();
		this->pollMouseEvents();
	}
}

void SFMLWindow::clearScreen()
{
	this->m_window->clear(sf::Color(220, 220, 220));
}

void SFMLWindow::displayScreen()
{
	this->m_window->display();
}

bool SFMLWindow::isWindowOpened() const noexcept
{
	return this->m_window->isOpen();
}

std::shared_ptr<sf::Event> SFMLWindow::getEvent() const noexcept
{
	return this->m_event;
}

void SFMLWindow::pollExitEvent()
{
	if (this->m_event->type == sf::Event::Closed) {
		this->closeWindow();
	}
}

void SFMLWindow::pollKeyboardEvents()
{
	if (this->m_event->type == sf::Event::KeyPressed) {
		if (this->m_event->key.code == sf::Keyboard::Escape) {
			this->m_event->type = sf::Event::Closed;
			this->closeWindow();
		}
	}
}

void SFMLWindow::pollMouseEvents()
{
	if (this->m_event->type == sf::Event::MouseMoved) {
		//sf::Vector2i mousePosition = sf::Mouse::getPosition();
		//std::cout << mousePosition.x << ":" << mousePosition.y << std::endl;
	}
}

void SFMLWindow::closeWindow()
{
	this->m_window->close();
}
