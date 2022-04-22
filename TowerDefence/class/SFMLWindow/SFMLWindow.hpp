#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/Entity.hpp"

class SFMLWindow {

public:
	SFMLWindow() = delete;
	SFMLWindow(const int16_t width, const int16_t height, const char* appName);
	~SFMLWindow();

public:
	void pollEvents();
	void clearScreen();
	void displayScreen();

public:
	bool isWindowOpened() const noexcept;
	std::shared_ptr<sf::RenderWindow> getWindow() { return this->m_window; };
	std::shared_ptr<sf::Event> getEvent() const noexcept;

//Events:
private:
	//Exit 
	void pollExitEvent();

	//Keyboard
	void pollKeyboardEvents();

	//Mouse
	void pollMouseEvents();

private:
	void closeWindow();

private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::shared_ptr<sf::Event> m_event;

private:
	int16_t m_windowWidth;
	int16_t m_windowHeight;
};