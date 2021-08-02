#pragma once
#include <string>
#include <memory>
#include <vector>
#include "VisualEntity.h"
#include "GUI/Gui.h"

namespace sf
{
	class RenderWindow;
}

namespace Render
{
	class VisualEntity;

	// Система для обработки окна и отрисовки графики
	class Render
	{
	private:
		Render() { }
		Render(const Render& instance) = delete;
		Render& operator=(const Render&) = delete;

		std::shared_ptr<sf::RenderWindow> m_window;

		std::string	m_name;
		int			m_width;
		int			m_height;

		// Для замера производительности
		float     m_fps;
		sf::Clock m_clock;
		sf::Time  m_previousTime;
		sf::Time  m_currentTime;

		std::shared_ptr<GUI::GUI> m_gui;
		
		// Визуальные сущности
		std::vector<VisualEntity> m_entities;
	public:
		static Render& Instance()
		{
			static Render instance;
			return instance;
		}

		// Запускаем инициализацию рендера игры
		void Init();

		// Деинициализация рендера игры
		void Deinit();
		
		// Обработка рендера на каждом кадре
		void OnFrame();

		// Получить указатель на окно рендера
		std::shared_ptr<sf::RenderWindow> GetWindow() const;

		// Получить систему GUI рендера
		std::shared_ptr<GUI::GUI> GetGUI();
	};
}