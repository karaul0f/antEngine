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

	m_gui = std::make_shared<GUI::GUI>();
	m_gui->Init();
}
//-----------------------------------------------------------------
void Render::OnFrame()
{
	m_window->clear();
	for (auto& entity : m_entities)
	{
		m_window->draw(entity.GetDrawable());
	}
	m_gui->OnFrame();
	m_window->display();
}
//-----------------------------------------------------------------
VisualEntity* Render::CreateEntity()
{
	m_entities.emplace_back();
	
	return nullptr;
}
//-----------------------------------------------------------------
VisualEntity* Render::GetEntityByName(const std::string& name)
{
	return nullptr;
}
//-----------------------------------------------------------------
std::vector<VisualEntity>& Render::GetEntities()
{
	return m_entities;
}
//-----------------------------------------------------------------
void Render::RemoveAllEntities()
{
	m_entities.clear();
}
//-----------------------------------------------------------------
std::shared_ptr<sf::RenderWindow> Render::GetWindow() const
{
	return std::shared_ptr<sf::RenderWindow>(m_window);
}
//-----------------------------------------------------------------
std::shared_ptr<GUI::GUI> Render::GetGUI()
{
	return std::shared_ptr<GUI::GUI>(m_gui);
}
//-----------------------------------------------------------------
void Render::Deinit()
{
	INFO("Деинициализация рендера");
	RemoveAllEntities();
	m_window->close();
}
//-----------------------------------------------------------------
}