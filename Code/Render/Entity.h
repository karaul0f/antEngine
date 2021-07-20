namespace Render
{
	// ����������� �������� ��� ���������
	class Entity
	{
		bool m_isActive;
		int  m_x;
		int  m_y;
	
	public:
		Entity();

		// ������� �� ��� ����������� ��������
		bool IsActive();

		// ���������� X-���������� �������� � ������� ������������
		void SetX(int x);

		// ���������� Y-���������� �������� � ������� ������������
		void SetY(int y);
	};
}