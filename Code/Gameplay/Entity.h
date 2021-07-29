#pragma once
#include "SFML/Graphics.hpp"

namespace Render
{
	class Entity;
}

namespace Gameplay
{
	// Игровая сущность
	class Entity
	{
		bool m_isActive;

	public:
		Entity();

		// Активна ли эта игровая сущность
		bool IsActive();

		// Обработка кадра игровой сущности
		void OnFrame();
	};
}