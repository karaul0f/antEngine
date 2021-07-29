#pragma once
#include "SFML/Graphics.hpp"

//namespace sf
//{
//	class Drawable;
//	class Sprite;
//}

namespace Render
{
	// ����������� �������� ��� ���������
	class Entity
	{
		bool m_isActive;
		int  m_x;
		int  m_y;
		
		sf::Sprite	m_sprite;
		sf::Texture m_texture;
	
	public:
		Entity();

		// ������� �� ��� ����������� ��������
		bool IsActive();

		// ���������� X-���������� �������� � ������� ������������
		void SetX(int x);

		// ���������� Y-���������� �������� � ������� ������������
		void SetY(int y);

		// �������� ����������� ��� ���������
		sf::Drawable& GetDrawable();
	};
}