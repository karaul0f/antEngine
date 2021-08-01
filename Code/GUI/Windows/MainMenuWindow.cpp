#include "MainMenuWindow.h"
#include "TGUI/TGUI.hpp"

namespace GUI
{
//-----------------------------------------------------------------
void MainMenuWindow::Activate(tgui::GuiSFML* gui)
{
	m_gui = gui;
	
	m_playButton = tgui::Button::create("Начать игру");
	m_playButton->onClick(&MainMenuWindow::HandlerPlayButtonClick, this);
	m_playButton->setPosition(260, 160);
	m_gui->add(m_playButton);

	m_playButton = tgui::Button::create("Авторы");
	m_playButton->setPosition(260, 200);
	m_gui->add(m_playButton);

	m_playButton = tgui::Button::create("Выйти из игры");
	m_playButton->setPosition(260, 240);
	m_gui->add(m_playButton);
}
//-----------------------------------------------------------------
void MainMenuWindow::Deactivate()
{
	m_gui->removeAllWidgets();
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerPlayButtonClick()
{
	m_playButton->setText("Lol");
}
//-----------------------------------------------------------------
}
