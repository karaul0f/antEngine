#pragma once

namespace tgui {
	class GuiSFML;
}

namespace GUI
{
	// Интерфейс окон GUI в игре
	class IWindow
	{
	public:
		// Обработать активацию окна
		virtual void Activate(tgui::GuiSFML* gui) = 0;

		// Обработать деактивацию окна
		virtual void Deactivate() = 0;
	};
}
