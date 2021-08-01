#include <memory>
#include "States/IState.h"

namespace Gameplay
{
	// Обработка игровой логики
	class Gameplay
	{
	private:
		std::unique_ptr<IState> m_currentState;
		
		bool m_isRun;
		
		Gameplay() {}
		Gameplay(const Gameplay& instance) = delete;
		Gameplay& operator=(const Gameplay&) = delete;

	public:
		static Gameplay& Instance()
		{
			static Gameplay instance;
			return instance;
		}

		// Запускаем инициализацию геймплея игры
		void Init();

		// Обработка кадра игровой логики
		void OnFrame();

		// Запущена ли обработка игровой логики?
		bool IsRun();

		// Закрыть игру
		void Close();

		// Установить состояние игры (меню, игра)
		void SetState(IState *state);
	};
}
