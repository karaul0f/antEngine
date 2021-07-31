#pragma once
#include "SFML/Graphics.hpp"

namespace Render
{
	// Графическая сущность для отрисовки
	class Entity
	{
		bool m_isActive;
		int  m_x;
		int  m_y;
		
		sf::Sprite	m_sprite;
		sf::Texture m_texture;
	
	public:
		Entity();

		// Получить изображение для отрисовки
		sf::Drawable& GetDrawable();
	};
}