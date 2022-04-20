#include "Application.hpp"

Application::Application()
	: m_window(config::WINDOW_WIDTH, config::WINDOW_HEIGHT, "Tower Defence: The Game")
{
	init();
}

Application::~Application()
{
}

void Application::init()
{ }

int Application::mainLoop()
{
	while (this->m_window.isWindowOpened()) {
		this->m_window.pollEvents();
		this->m_window.render();
	}

	return 0;
}
