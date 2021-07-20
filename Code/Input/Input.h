namespace Input
{
	// ������� �����
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

		// ��������� ������������� ������� �����
		void Init();

		// ��������� ����� �� ������ �����
		void OnFrame();

		// �������� �� ��������� �����?
		bool IsEnabled();
	};
}