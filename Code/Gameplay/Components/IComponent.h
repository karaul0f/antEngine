namespace Gameplay
{
	// ��������� ��� ����������� ������� ��������
	class IComponent
	{
	public:
		// ��������� ����� ������� ������
		virtual void OnFrame() = 0;
	};
}