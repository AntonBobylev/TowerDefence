#pragma once
#include <SFML/Graphics.hpp>

class SFMLWindow {

public:
	SFMLWindow();
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
	void init();
	void closeWindow();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;
};