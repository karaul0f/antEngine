#include "MainMenuWindow.h"

#include "Gameplay/Gameplay.h"
#include "Gameplay/States/GameState.h"
#include "Resources/ResourceManager.h"
#include "TGUI/TGUI.hpp"

namespace GUI
{
//-----------------------------------------------------------------
void MainMenuWindow::Activate(tgui::GuiSFML* gui)
{
	m_gui = gui;
	m_gui->loadWidgetsFromFile("Data/Windows/MainMenu.txt");

	// Кнопки меню
	auto element = std::static_pointer_cast<tgui::Button>(m_gui->get("ButtonPlay"));
	element->onClick(&MainMenuWindow::HandlerPlayButtonClick, this);
	m_guiElements.emplace(State::Menu, element);
	m_gui->add(element);

	element = std::static_pointer_cast<tgui::Button>(m_gui->get("ButtonSettings"));
	element->onClick(&MainMenuWindow::HandlerSettingsButtonClick, this);
	m_guiElements.emplace(State::Menu, element);
	m_gui->add(element);

	element = std::static_pointer_cast<tgui::Button>(m_gui->get("ButtonCredits"));
	element->onClick(&MainMenuWindow::HandlerCreditsButtonClick, this);
	m_guiElements.emplace(State::Menu, element);
	m_gui->add(element);

	element = std::static_pointer_cast<tgui::Button>(m_gui->get("ButtonExit"));
	element->onClick(&MainMenuWindow::HandlerExitButtonClick, this);
	m_guiElements.emplace(State::Menu, element);
	m_gui->add(element);

	// Авторы
	LoadCreditsFile();
	auto labelElem = std::static_pointer_cast<tgui::Label>(m_gui->get("LabelCredits"));
	labelElem->setText(m_creditsText);
	m_guiElements.emplace(State::Credits, labelElem);
	m_gui->add(labelElem);

	// Настройка громкости
	auto sliderElement = std::static_pointer_cast<tgui::Slider>(m_gui->get("SliderVolume"));
	sliderElement->setValue(Audio::AudioPlayer::Instance().GetVolume());
	sliderElement->onValueChange(&MainMenuWindow::HandlerSliderValueChange, this);
	m_guiElements.emplace(State::Settings, sliderElement);
	m_gui->add(sliderElement);

	// Возврат в главное меню
	m_returnButton = std::static_pointer_cast<tgui::Button>(m_gui->get("ButtonBack"));
	m_returnButton->onClick(&MainMenuWindow::HandlerReturnButtonClick, this);
	m_gui->add(m_returnButton);

	SetTab(State::Menu);
	Audio::AudioPlayer::Instance().PlayMusic(Resources::ResourceManager::Instance().GetMusicByName("Music0"), true);
}
//-----------------------------------------------------------------
void MainMenuWindow::Deactivate()
{
	Audio::AudioPlayer::Instance().StopAllSounds();
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
	SetTab(State::Settings);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerCreditsButtonClick()
{
	SetTab(State::Credits);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerReturnButtonClick()
{
	SetTab(State::Menu);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerExitButtonClick()
{
	Gameplay::Gameplay::Instance().Close();
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerSliderValueChange()
{ 
	auto sliderElement = std::static_pointer_cast<tgui::Slider>(m_guiElements.equal_range(State::Settings).first->second);
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
	for (auto& item : m_guiElements)
		item.second->setVisible(false);

	m_returnButton->setVisible(tab != State::Menu);
	
	auto visibleItems = m_guiElements.equal_range(tab);
	for (auto& it = visibleItems.first; it != visibleItems.second; it++)
		it->second->setVisible(true);
}
//-----------------------------------------------------------------
}
