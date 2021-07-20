#include "Entity.h"

#include <SFML/Graphics.hpp>

namespace
{
	const int MAX_VISUAL_ENITIES = 400;
}

namespace Render
{
	// Система для обработки окна и отрисовки графики
	class Render
	{
	private:
		Render() {}
		Render(const Render& instance) = delete;
		Render& operator=(const Render&) = delete;

		std::unique_ptr<sf::RenderWindow> m_window;

		std::string	m_name;
		int			m_width;
		int			m_height;

		// Пул визуальных объектов
		Entity m_entities[MAX_VISUAL_ENITIES];
	public:
		static Render& Instance()
		{
			static Render instance;
			return instance;
		}

		// Запускаем инициализацию рендера игры
		void Init();
		
		// Обработка рендера на каждом кадре
		void OnFrame();
	};
}