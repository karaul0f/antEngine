#include "MainMenuWindow.h"

#include "Gameplay/Gameplay.h"
#include "Gameplay/States/GameState.h"
#include "TGUI/TGUI.hpp"

namespace GUI
{
//-----------------------------------------------------------------
void MainMenuWindow::Activate(tgui::GuiSFML* gui)
{
	m_gui = gui;

	m_playButton = tgui::Button::create("Начать игру");
	m_playButton->onClick(&MainMenuWindow::HandlerPlayButtonClick, this);
	m_playButton->setPosition("50%", "40%");
	m_playButton->setOrigin(0.5f, 0.5f);
	m_gui->add(m_playButton);

	m_creditsButton = tgui::Button::create("Авторы");
	m_creditsButton->setPosition("50%", "50%");
	m_creditsButton->setOrigin(0.5f, 0.5f);
	m_gui->add(m_creditsButton);

	m_exitButton = tgui::Button::create("Выйти из игры");
	m_exitButton->onClick(&MainMenuWindow::HandlerExitButtonClick, this);
	m_exitButton->setPosition("50%", "60%");
	m_exitButton->setOrigin(0.5f, 0.5f);
	m_gui->add(m_exitButton);
}
//-----------------------------------------------------------------
void MainMenuWindow::Deactivate()
{
	m_gui->removeAllWidgets();
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerPlayButtonClick()
{
	Gameplay::Gameplay::Instance().SetState(new Gameplay::GameState);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerExitButtonClick()
{
	Gameplay::Gameplay::Instance().Close();
}
//-----------------------------------------------------------------
}
