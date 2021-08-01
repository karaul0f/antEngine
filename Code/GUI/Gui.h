#include <memory>

namespace sf {
	class RenderWindow;
}

namespace Gui
{
	// Класс для обрботки GUI игры
	class Gui
	{
	private:
		Gui() { }
		Gui(const Gui& instance) = delete;
		Gui& operator=(const Gui&) = delete;

		std::shared_ptr<sf::RenderWindow> m_window;
	public:
		static Gui& Instance()
		{
			static Gui instance;
			return instance;
		}

		// Запускаем инициализацию GUI игры
		void Init();

		// Обработка GUI игры на каждом кадре
		void OnFrame();
	};
}
