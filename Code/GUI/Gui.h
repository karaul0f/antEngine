#include <memory>

namespace sf {
	class RenderWindow;
}

namespace Gui
{
	// ����� ��� �������� GUI ����
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

		// ��������� ������������� GUI ����
		void Init();

		// ��������� GUI ���� �� ������ �����
		void OnFrame();
	};
}
