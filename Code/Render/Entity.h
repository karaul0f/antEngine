#pragma once
#include "SFML/Graphics.hpp"

//namespace sf
//{
//	class Drawable;
//	class Sprite;
//}

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

		// Активна ли эта графическая сущность
		bool IsActive();

		// Установить X-координату сущности в мировом пространстве
		void SetX(int x);

		// Установить Y-координату сущности в мировом пространстве
		void SetY(int y);

		// Получить изображение для отрисовки
		sf::Drawable& GetDrawable();
	};
}