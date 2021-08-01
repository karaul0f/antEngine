#include <memory>
#include "States/IState.h"

namespace Gameplay
{
	// ��������� ������� ������
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

		// ��������� ������������� �������� ����
		void Init();

		// ��������� ����� ������� ������
		void OnFrame();

		// �������� �� ��������� ������� ������?
		bool IsRun();

		// ������� ����
		void Close();

		// ���������� ��������� ���� (����, ����)
		void SetState(IState *state);
	};
}
