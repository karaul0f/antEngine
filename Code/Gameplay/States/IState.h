namespace Gameplay
{
	// Интерфейс состояния движка
	class IState
	{
	public:
		// Обработка кадра стейта
		virtual void OnFrame() = 0;
	};
}