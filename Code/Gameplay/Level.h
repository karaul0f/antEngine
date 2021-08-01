#pragma once
#include "Entity.h"
#include <memory>
#include <vector>

namespace Gameplay
{
	// Игровой уровень GameState'а
	class Level
	{
		std::vector<Entity> m_entities;
	public:
		// Действия при активации уровня
		void Activate();

		// Действия при деактивации уровня
		void Deactivate();
		
		// Обработка уровня на каждом кадре
		void OnFrame();
	};

}
