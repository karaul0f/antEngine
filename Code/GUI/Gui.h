#pragma once
#include <memory>
#include "TGUI/TGUI.hpp"

namespace sf {
	class RenderWindow;
}

namespace GUI
{
	// Класс для обработки GUI игры
	class GUI
	{
		bool m_isFirstFrame;
		
		tgui::GuiSFML m_gui;
	public:
		// Обработать игровое событие ввода
		void HandleEvent(sf::Event sfmlEvent);
		
		// Запускаем инициализацию GUI игры
		void Init();

		// Обработка GUI игры на каждом кадре
		void OnFrame();
	};
}
