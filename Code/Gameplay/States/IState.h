#pragma once
namespace Gameplay
{
	// Интерфейс состояния движка
	class IState
	{
	public:
		// Обработка кадра стейта
		virtual void OnFrame() = 0;

		// Действия при активации стейста
		virtual void Activate() = 0;

		// Действия при деактивации стейста
		virtual void Deactivate() = 0;
	};
}