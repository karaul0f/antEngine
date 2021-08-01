#include "Gui.h"

#include "Render/Render.h"

namespace GUI
{
//-----------------------------------------------------------------
void GUI::OnFrame()
{
	if (m_isFirstFrame)
	{
		m_isFirstFrame = false;

		auto button = tgui::Button::create("Play Game");
		m_gui.add(button);
	}

	m_gui.draw();
}
//-----------------------------------------------------------------
void GUI::HandleEvent(sf::Event sfmlEvent)
{
	m_gui.handleEvent(sfmlEvent);
}
//-----------------------------------------------------------------
void GUI::Init()
{
	m_gui.setTarget(*Render::Render::Instance().GetWindow());
	m_isFirstFrame = true;
}
//-----------------------------------------------------------------
}
