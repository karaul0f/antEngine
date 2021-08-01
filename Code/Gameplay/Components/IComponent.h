namespace Gameplay
{
	// Интерфейс для компонентов игровой сущности
	class IComponent
	{
	public:
		// Обработка кадра игровой логики
		virtual void OnFrame() = 0;
	};
}