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

	// Кнопки меню
	auto element = tgui::Button::create("Начать игру");
	element->onClick(&MainMenuWindow::HandlerPlayButtonClick, this);
	element->setPosition("50%", "30%");
	element->setOrigin(0.5f, 0.5f);
	m_guiElements.emplace(Menu, element);
	m_gui->add(element);

	element = tgui::Button::create("Настройки");
	element->onClick(&MainMenuWindow::HandlerSettingsButtonClick, this);
	element->setPosition("50%", "40%");
	element->setOrigin(0.5f, 0.5f);
	m_guiElements.emplace(Menu, element);
	m_gui->add(element);

	element = tgui::Button::create("Авторы");
	element->onClick(&MainMenuWindow::HandlerCreditsButtonClick, this);
	element->setPosition("50%", "50%");
	element->setOrigin(0.5f, 0.5f);
	m_guiElements.emplace(Menu, element);
	m_gui->add(element);

	element = tgui::Button::create("Выйти из игры");
	element->onClick(&MainMenuWindow::HandlerExitButtonClick, this);
	element->setPosition("50%", "60%");
	element->setOrigin(0.5f, 0.5f);
	m_guiElements.emplace(Menu, element);
	m_gui->add(element);

	// Авторы
	LoadCreditsFile();
	auto labelElem = tgui::Label::create(m_creditsText);
	labelElem->setPosition("50%", "50%");
	labelElem->setOrigin(0.5f, 0.5f);
	labelElem->setTextSize(20);
	labelElem->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
	m_guiElements.emplace(Credits, labelElem);
	m_gui->add(labelElem);

	// Настройка громкости
	auto sliderElement = tgui::Slider::create();
	sliderElement->setPosition("50%", "50%");
	sliderElement->setOrigin(0.5f, 0.5f);
	sliderElement->onValueChange(&MainMenuWindow::HandlerSliderValueChange, this);
	sliderElement->setMaximum(100);
	sliderElement->setMinimum(0);
	sliderElement->setValue(50);
	m_guiElements.emplace(Settings, sliderElement);
	m_gui->add(sliderElement);

	// Возврат в главное меню
	m_returnButton = tgui::Button::create("Русские назад");
	m_returnButton->onClick(&MainMenuWindow::HandlerReturnButtonClick, this);
	m_returnButton->setPosition("15%", "90%");
	m_returnButton->setOrigin(0.5f, 0.5f);
	m_gui->add(m_returnButton);

	SetTab(Menu);
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
void MainMenuWindow::HandlerSettingsButtonClick()
{
	SetTab(Settings);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerCreditsButtonClick()
{
	SetTab(Credits);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerReturnButtonClick()
{
	SetTab(Menu);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerExitButtonClick()
{
	Gameplay::Gameplay::Instance().Close();
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerSliderValueChange()
{
	// TO DO добавить изменение громкости звука при 
	auto&& sliderElement = std::static_pointer_cast<tgui::Slider>(m_guiElements.equal_range(Settings).first->second);
	Audio::AudioPlayer::Instance().SetVolume(sliderElement->getValue());
}
//-----------------------------------------------------------------
void MainMenuWindow::LoadCreditsFile()
{
	std::ifstream creditsFile("Data/Credits.txt");
	std::string line;
	while (std::getline(creditsFile, line))
	{
		m_creditsText += line;
		m_creditsText += '\n';
	}
}
//-----------------------------------------------------------------
void MainMenuWindow::SetTab(State tab)
{
	for (auto item : m_guiElements)
		item.second->setVisible(false);

	m_returnButton->setVisible(tab != Menu);
	
	auto visibleItems = m_guiElements.equal_range(tab);
	for (auto it = visibleItems.first; it != visibleItems.second; it++)
		it->second->setVisible(true);
}
//-----------------------------------------------------------------
}
