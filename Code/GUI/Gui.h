#pragma once
#include <memory>
#include "TGUI/TGUI.hpp"
#include "GUI/Windows/IWindow.h"

namespace sf {
	class RenderWindow;
}

namespace GUI
{
	// Класс для обработки GUI игры
	class GUI
	{
		std::unique_ptr<IWindow> m_currentWindow;
		
		tgui::GuiSFML m_gui;
	public:
		// Обработать игровое событие ввода
		void HandleEvent(sf::Event sfmlEvent);
		
		// Запускаем инициализацию GUI игры
		void Init();

		// Обработка GUI игры на каждом кадре
		void OnFrame();

		// Установить окно GUI для отрисовки
		void SetWindow(IWindow* window);
	};
}
