#pragma once
#include "SFML/Graphics.hpp"

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

		// �������� ����������� ��� ���������
		sf::Drawable& GetDrawable();
	};
}