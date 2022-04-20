#pragma once
#include "../SFMLWindow/SFMLWindow.hpp"

class Application {

public:
	Application();
	~Application();

public:
	int mainLoop();

private:
	void init();

private:
	SFMLWindow m_window;
};