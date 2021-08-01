#pragma once
#include "SFML/Graphics.hpp"

namespace Render
{
	// Графическая сущность для отрисовки
	class VisualEntity
	{
		bool m_isActive;
		
		sf::Sprite m_sprite;
		sf::Texture m_texture;
	public:
		VisualEntity();

		// Получить изображение для отрисовки
		sf::Drawable& GetDrawable();
	};
}