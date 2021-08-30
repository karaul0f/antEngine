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
		enum class State
		{
			Menu,
			Settings,
			Credits
		};

		// Обработчики событий для кнопок
		void HandlerPlayButtonClick();
		void HandlerSettingsButtonClick();
		void HandlerCreditsButtonClick();
		void HandlerReturnButtonClick();
		void HandlerExitButtonClick();

		// Обработчик измения значения слайдера
		void HandlerSliderValueChange();

		// Загрузка текста из файла
		void LoadCreditsFile();

		// Изменение состояния окна
		void SetTab(State tab);
		
		std::shared_ptr<tgui::Button>	m_returnButton;

		std::multimap<State, std::shared_ptr<tgui::Widget>> m_guiElements;
		
		std::string m_creditsText;

		tgui::GuiSFML* m_gui;						         
													         
	public:	
		void Activate(tgui::GuiSFML* gui) override;	   	     
		void Deactivate() override;						     
	};
}
