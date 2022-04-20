#pragma once
#include <SFML/Graphics.hpp>

class SFMLWindow {

public:
	SFMLWindow() = delete;
	SFMLWindow(const int16_t width, const int16_t height, const char* appName);
	~SFMLWindow();

public:
	void pollEvents();
	void render();

public:
	bool isWindowOpened() const noexcept;

//Events:
private:
	//Exit 
	void pollExitEvent();

	//Keyboard
	void pollKeyboardEvents();


private:
	void closeWindow();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;

private:
	int16_t m_windowWidth;
	int16_t m_windowHeight;
};