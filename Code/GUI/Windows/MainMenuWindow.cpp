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

	m_guiElements.insert(make_pair("Credits", tgui::Label::create()));
	auto& element = (--m_guiElements.equal_range("Credits").second)->second;
	element->setPosition("50%", "50%");
	element->setOrigin(0.5f, 0.5f);
	element->setTextSize(20);
	auto&& labelElem = std::static_pointer_cast<tgui::Label>(element);
	labelElem->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
	m_gui->add(element);

	m_guiElements.insert(make_pair("Menu", tgui::Button::create("Начать игру")));
	element = (--m_guiElements.equal_range("Menu").second)->second;
	std::static_pointer_cast<tgui::ClickableWidget>(element)->onClick(&MainMenuWindow::HandlerPlayButtonClick, this);
	element->setPosition("50%", "30%");
	element->setOrigin(0.5f, 0.5f);
	m_gui->add(element);

	m_guiElements.insert(make_pair("Menu", tgui::Button::create("Настройки")));
	element = (--m_guiElements.equal_range("Menu").second)->second;
	std::static_pointer_cast<tgui::ClickableWidget>(element)->onClick(&MainMenuWindow::HandlerSettingsButtonClick, this);
	element->setPosition("50%", "40%");
	element->setOrigin(0.5f, 0.5f);
	m_gui->add(element);

	// TO DO не отображается кнопка авторы
	m_guiElements.insert(make_pair("Menu", tgui::Button::create("Авторы")));
	element = (--m_guiElements.equal_range("Menu").second)->second;
	std::static_pointer_cast<tgui::ClickableWidget>(element)->onClick(&MainMenuWindow::HandlerCreditsButtonClick, this);
	element->setPosition("50%", "50%");
	element->setOrigin(0.5f, 0.5f);
	m_gui->add(element);

	m_guiElements.insert(make_pair("Menu", tgui::Button::create("Выйти из игры")));
	element = (--m_guiElements.equal_range("Menu").second)->second;
	std::static_pointer_cast<tgui::ClickableWidget>(element)->onClick(&MainMenuWindow::HandlerExitButtonClick, this);
	element->setPosition("50%", "60%");
	element->setOrigin(0.5f, 0.5f);
	m_gui->add(element);

	m_returnButton = tgui::Button::create("Русские назад");
	m_returnButton->onClick(&MainMenuWindow::HandlerReturnButtonClick, this);
	m_returnButton->setPosition("10%", "90%");
	m_returnButton->setOrigin(0.5f, 0.5f);
	m_returnButton->setVisible(false);
	m_gui->add(m_returnButton);

	// TO DO не отображается слайдер
	m_guiElements.insert(make_pair("Volume", tgui::Slider::create()));
	element = (--m_guiElements.equal_range("Volume").first)->second;
	auto&& sliderElement = std::static_pointer_cast<tgui::Slider>(element);
	sliderElement->setPosition("50%", "50%");
	sliderElement->setOrigin(0.5f, 0.5f);
	sliderElement->onValueChange(&MainMenuWindow::HandlerSliderValueChange, this);
	sliderElement->setMaximum(100);
	sliderElement->setMinimum(0);
	sliderElement->setValue(50);
	//m_guiElements.rbegin()->second->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
	m_gui->add(sliderElement);

	LoadCreditsFile();
	SetTab("Menu");
	m_currentTab = "Menu";
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
	SetTab("Credits");
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerCreditsButtonClick()
{
	SetTab("Volume");
	// TO DO добавить отображение текста в label
	//m_creditsLabel->setText(m_creditsText);
}
//-----------------------------------------------------------------
void MainMenuWindow::HandlerReturnButtonClick()
{
	SetTab("Menu");
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
	//Audio::AudioPlayer::Instance().SetVolume(m_volumeSlider->getValue());
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
void MainMenuWindow::SetTab(std::string tab)
{
	m_returnButton->setVisible(tab != "Menu");
	for (auto& element : m_guiElements)
	{
		if (element.first == m_currentTab) 
			element.second->setVisible(false);
		else if (element.first == tab) 
			element.second->setVisible(true);
	}
	m_currentTab = tab;
	for (auto& element : m_guiElements)
	{
		//if (element.first == m_currentTab)
			//element.second->setVisible(true);
		//else if (element.first == tab)
			//element.second->setVisible(true);
	}
}
//-----------------------------------------------------------------
}
