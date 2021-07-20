#include "Entity.h"

#include <SFML/Graphics.hpp>

namespace
{
	const int MAX_VISUAL_ENITIES = 400;
}

namespace Render
{
	// ������� ��� ��������� ���� � ��������� �������
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

		// ��� ���������� ��������
		Entity m_entities[MAX_VISUAL_ENITIES];
	public:
		static Render& Instance()
		{
			static Render instance;
			return instance;
		}

		// ��������� ������������� ������� ����
		void Init();
		
		// ��������� ������� �� ������ �����
		void OnFrame();
	};
}