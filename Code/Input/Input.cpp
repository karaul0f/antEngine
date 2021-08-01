#include "Input.h"
#include "Render/Render.h"
#include "Core/Logger.h"
#include "Gameplay/Gameplay.h"
#include "SFML/Graphics.hpp"

namespace Input
{
//-----------------------------------------------------------------
void Input::Init()
{
	INFO("Инициализация системы ввода");
	m_window = Render::Render::Instance().GetWindow();
	m_gui = Render::Render::Instance().GetGUI();
}
//-----------------------------------------------------------------
void Input::OnFrame()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		m_gui->HandleEvent(event);
		
		if (event.type == sf::Event::KeyPressed)
			OnKeyPressed();
		else if (event.type == sf::Event::KeyReleased)
			OnKeyReleased();
		if (event.type == sf::Event::Closed)
			Gameplay::Gameplay::Instance().Close();
	}
}
//-----------------------------------------------------------------
bool Input::IsEnabled()
{
	return m_isInputEnabled;
}
//-----------------------------------------------------------------
}

