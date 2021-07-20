namespace Input
{
	// Система ввода
	class Input
	{
	private:
		bool m_isInputEnabled;

		Input() {}
		Input(const Input& instance) = delete;
		Input& operator=(const Input&) = delete;

	public:
		static Input& Instance()
		{
			static Input instance;
			return instance;
		}

		// Запускаем инициализацию систему ввода
		void Init();

		// Обработка ввода на каждом кадре
		void OnFrame();

		// Включена ли обработка ввода?
		bool IsEnabled();
	};
}