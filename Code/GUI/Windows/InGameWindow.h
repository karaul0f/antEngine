#pragma once
#include <memory>

#include "IWindow.h"

namespace tgui {
	class Label;
}

namespace GUI
{
	// Интерфейс главного меню игры
	class InGameWindow : public IWindow
	{
		tgui::GuiSFML* m_gui;

		std::shared_ptr<tgui::Label> m_inGameText;
	public:
		void Activate(tgui::GuiSFML* gui) override;
		void Deactivate() override;
	};
}
