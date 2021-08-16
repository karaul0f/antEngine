#pragma once
#include <map>
#include <memory>
#include <fstream>

#include "IWindow.h"
#include "Audio/AudioPlayer.h"

namespace tgui {
	class Button;
	class Picture;
	class Slider;
	class Label;
	class Widget;
	class ClickableWidget;
}

namespace GUI
{
	// Интерфейс главного меню игры
	class MainMenuWindow: public IWindow
	{
		enum State
		{
			Menu,
			Settings,
			Credits
		};

		void HandlerPlayButtonClick();
		void HandlerSettingsButtonClick();
		void HandlerCreditsButtonClick();
		void HandlerReturnButtonClick();
		void HandlerExitButtonClick();

		void HandlerSliderValueChange();

		void LoadCreditsFile();
		void SetTab(std::string tab);
		
		std::shared_ptr<tgui::Button>	m_returnButton;

		std::multimap<std::string, std::shared_ptr<tgui::Widget>> m_guiElements;
		
		std::string m_currentTab;
		std::string m_creditsText;

		tgui::GuiSFML* m_gui;						         
													         
	public:											   	     
		void Activate(tgui::GuiSFML* gui) override;	   	     
		void Deactivate() override;						     
	};
}
