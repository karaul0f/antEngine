#include "Input.h"
#include "Render/Render.h"
#include "Core/Logger.h"
#include "SFML/Graphics.hpp"

namespace Input
{
//-----------------------------------------------------------------
void Input::Init()
{
	INFO("Инициализация системы ввода");
	m_window = Render::Render::Instance().GetWindow();
}
//-----------------------------------------------------------------
void Input::OnFrame()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
			OnKeyPressed();
		else if (event.type == sf::Event::KeyReleased)
			OnKeyReleased();
		else if (event.type == sf::Event::Closed)
			m_window->close();
	}
}
//-----------------------------------------------------------------
bool Input::IsEnabled()
{
	return m_isInputEnabled;
}
//-----------------------------------------------------------------
}

