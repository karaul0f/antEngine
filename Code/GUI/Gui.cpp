#include "Gui.h"

#include "Render/Render.h"
#include "Windows/MainMenuWindow.h"

namespace GUI
{
//-----------------------------------------------------------------
void GUI::OnFrame()
{
	m_gui.draw();
}
//-----------------------------------------------------------------
void GUI::SetWindow(IWindow* window)
{
	if (m_currentWindow != nullptr)
		m_currentWindow->Deactivate();
	
	m_currentWindow = std::unique_ptr<IWindow>(window);
	m_currentWindow->Activate(&m_gui);
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

	SetWindow(new MainMenuWindow);
}
//-----------------------------------------------------------------
}
