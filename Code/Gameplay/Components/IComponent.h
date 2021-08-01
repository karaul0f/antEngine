namespace Gameplay
{
	// Интерфейс для компонентов игровой сущности
	class IComponent
	{
	public:
		// Активация компонента
		virtual void Activate() = 0;

		// Деактивация компонента
		virtual void Deactivate() = 0;
		
		// Обработка кадра игровой логики
		virtual void OnFrame() = 0;
	};
}