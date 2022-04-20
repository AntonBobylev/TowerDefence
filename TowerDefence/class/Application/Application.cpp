#include "Application.hpp"

Application::Application()
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
