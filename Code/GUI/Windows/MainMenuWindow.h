#pragma once
#include <memory>
#include <TGUI/Widgets/Button.hpp>

#include "IWindow.h"

namespace GUI
{
	// Интерфейс главного меню игры
	class MainMenuWindow: public IWindow
	{
		void HandlerPlayButtonClick();
		
		std::shared_ptr<tgui::Button> m_playButton;
		std::shared_ptr<tgui::Button> m_creditsButton;
		std::shared_ptr<tgui::Button> m_exitButton;

		tgui::GuiSFML* m_gui;
	
	public:
		void Activate(tgui::GuiSFML* gui) override;
		void Deactivate() override;
	};
}
