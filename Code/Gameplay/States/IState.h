#pragma once
namespace Gameplay
{
	// ��������� ��������� ������
	class IState
	{
	public:
		// ��������� ����� ������
		virtual void OnFrame() = 0;

		// �������� ��� ��������� �������
		virtual void Activate() = 0;

		// �������� ��� ����������� �������
		virtual void Deactivate() = 0;
	};
}