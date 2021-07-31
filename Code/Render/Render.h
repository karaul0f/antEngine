#pragma once
#include "Entity.h"
#include <string>
#include <memory>
#include <vector>

namespace
{
	const int MAX_VISUAL_ENITIES = 400;
}

namespace sf
{
	class RenderWindow;
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

		std::shared_ptr<sf::RenderWindow> m_window;

		std::string	m_name;
		int			m_width;
		int			m_height;

		// ���������� ��������
		std::vector<Entity> m_entities;
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

		// �������� ��������� �� ���� �������
		std::shared_ptr<sf::RenderWindow> GetWindow() const;
	};
}