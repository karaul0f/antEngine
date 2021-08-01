#pragma once
#include "SFML/Graphics.hpp"
#include "Components/IComponent.h"

namespace Gameplay
{
	// Игровая сущность
	class Entity
	{
		bool m_isActive;
		
		std::vector<std::shared_ptr<IComponent>> m_components;
	public:
		Entity();

		// Активна ли эта игровая сущность
		bool IsActive();

		// Обработка кадра игровой сущности
		virtual void OnFrame();
	};
}