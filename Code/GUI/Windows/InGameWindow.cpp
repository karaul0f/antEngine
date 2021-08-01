#include "InGameWindow.h"
#include "TGUI/TGUI.hpp"

namespace GUI
{
//-----------------------------------------------------------------
void InGameWindow::Activate(tgui::GuiSFML* gui)
{
	m_gui = gui;

	m_inGameText = tgui::Label::create("InGameGui");
	m_inGameText->setPosition("10%", "10%");
	m_gui->add(m_inGameText);
}
//-----------------------------------------------------------------
void InGameWindow::Deactivate()
{
	m_gui->removeAllWidgets();
}
//-----------------------------------------------------------------
}
