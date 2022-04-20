#include "SFMLWindow.hpp"

SFMLWindow::SFMLWindow(const int16_t width, const int16_t height, const char* appName)
	: m_window(
		sf::VideoMode(width, height),
		appName, sf::Style::Close)
	, m_windowWidth(width)
	, m_windowHeight(height)
	, m_event()
{ }

SFMLWindow::~SFMLWindow()
{ }

void SFMLWindow::pollEvents()
{
	while (this->m_window.pollEvent(this->m_event)) {
		this->pollExitEvent();
		this->pollKeyboardEvents();
	}
}

void SFMLWindow::render()
{
	this->m_window.clear(sf::Color(220, 220, 220));
	this->m_window.display();
}

bool SFMLWindow::isWindowOpened() const noexcept
{
	return this->m_window.isOpen();
}

void SFMLWindow::pollExitEvent()
{
	if (this->m_event.type == sf::Event::Closed) {
		this->closeWindow();
	}
}

void SFMLWindow::pollKeyboardEvents()
{
	if (this->m_event.type == sf::Event::KeyPressed) {
		if (this->m_event.key.code == sf::Keyboard::Escape) {
			this->m_event.type = sf::Event::Closed;
			this->closeWindow();
		}
	}
}

void SFMLWindow::closeWindow()
{
	this->m_window.close();
}
