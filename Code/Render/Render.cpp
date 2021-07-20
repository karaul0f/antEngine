#include "Render.h"
#include "../Core/Logger.h"

namespace
{
	const std::string	DEFAULT_WINDOW_NAME = "antEngine";
	const int			DEFAULT_WINDOW_WIDTH = 640;
	const int			DEFAULT_WINDOW_HEIGHT = 480;
}

namespace Render
{
//-----------------------------------------------------------------
void Render::Init()
{
	INFO("Инициализация рендера");
	
	m_name = DEFAULT_WINDOW_NAME;
	m_width = DEFAULT_WINDOW_WIDTH;
	m_height = DEFAULT_WINDOW_HEIGHT;
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), m_name);
}
//-----------------------------------------------------------------
void Render::OnFrame()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window->close();
	}

	m_window->clear();
	for (auto entity : m_entities)
	{
		//m_window->draw(entity);
	}
	m_window->display();
}
//-----------------------------------------------------------------
}