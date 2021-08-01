#pragma once
#include <boost/signals2.hpp>

namespace GUI {
	class GUI;
}

namespace sf
{
	class RenderWindow;
}

namespace Input
{
	// Система ввода
	class Input
	{
	private:
		bool m_isInputEnabled;

		Input() {}
		Input(const Input& instance) = delete;
		Input& operator=(const Input&) = delete;

		std::shared_ptr<sf::RenderWindow> m_window;
		std::shared_ptr<GUI::GUI>         m_gui;
	public:
		static Input& Instance()
		{
			static Input instance;
			return instance;
		}
		
		// Событие нажатия клавиши
		boost::signals2::signal<void()> OnKeyPressed;

		// Событие отпускания клавиши
		boost::signals2::signal<void()> OnKeyReleased;
		
		// Запускаем инициализацию системы ввода
		void Init();

		// Обработка ввода на каждом кадре
		void OnFrame();

		// Включена ли обработка ввода?
		bool IsEnabled();
	};
}
