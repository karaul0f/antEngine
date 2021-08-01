#include "Render.h"

#include "Core/Logger.h"
#include <SFML/Graphics.hpp>

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
	m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), m_name);

	//m_entities.emplace_back();
}
//-----------------------------------------------------------------
void Render::OnFrame()
{
	m_window->clear();
	for (auto entity : m_entities)
	{
		m_window->draw(entity.GetDrawable());
	}
	m_window->display();
}
//-----------------------------------------------------------------
std::shared_ptr<sf::RenderWindow> Render::GetWindow() const
{
	return std::shared_ptr<sf::RenderWindow>(m_window);
}
//-----------------------------------------------------------------
}