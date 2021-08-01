#pragma once
#include <memory>

#include "IWindow.h"

namespace tgui {
	class Button;
	class Picture;
}

namespace GUI
{
	// Интерфейс главного меню игры
	class MainMenuWindow: public IWindow
	{
		void HandlerPlayButtonClick();
		void HandlerExitButtonClick();
		
		std::shared_ptr<tgui::Button> m_playButton;
		std::shared_ptr<tgui::Button> m_creditsButton;
		std::shared_ptr<tgui::Button> m_exitButton;
		std::shared_ptr<tgui::Picture> m_gamelogoPicture;

		tgui::GuiSFML* m_gui;
	
	public:
		void Activate(tgui::GuiSFML* gui) override;
		void Deactivate() override;
	};
}
