#pragma once
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