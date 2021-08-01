namespace Gameplay
{
	// ��������� ��� ����������� ������� ��������
	class IComponent
	{
	public:
		// ��������� ����������
		virtual void Activate() = 0;

		// ����������� ����������
		virtual void Deactivate() = 0;
		
		// ��������� ����� ������� ������
		virtual void OnFrame() = 0;
	};
}