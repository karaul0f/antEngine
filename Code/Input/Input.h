#pragma once
#include <boost/signals2.hpp>

namespace sf
{
	class RenderWindow;
}

namespace Input
{
	// ������� �����
	class Input
	{
	private:
		bool m_isInputEnabled;

		Input() {}
		Input(const Input& instance) = delete;
		Input& operator=(const Input&) = delete;

		std::shared_ptr<sf::RenderWindow> m_window;
	public:
		static Input& Instance()
		{
			static Input instance;
			return instance;
		}
		
		// ������� ������� �������
		boost::signals2::signal<void()> OnKeyPressed;

		// ������� ���������� �������
		boost::signals2::signal<void()> OnKeyReleased;
		
		// ��������� ������������� ������� �����
		void Init();

		// ��������� ����� �� ������ �����
		void OnFrame();

		// �������� �� ��������� �����?
		bool IsEnabled();
	};
}