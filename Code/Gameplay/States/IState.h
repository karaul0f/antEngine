namespace Gameplay
{
	// ��������� ��������� ������
	class IState
	{
	public:
		// ��������� ����� ������
		virtual void OnFrame() = 0;
	};
}