#pragma once
#include "IComponent.h"

namespace Gameplay
{
	// Интерфейс для компонентов игровой сущности
	class GraphicComponent: public IComponent
	{
	public:
		// Активация компонента
		void Activate() override;

		// Деактивация компонента
		void Deactivate() override;

		// Обработка кадра игровой логики
		void OnFrame() override;
	};
}