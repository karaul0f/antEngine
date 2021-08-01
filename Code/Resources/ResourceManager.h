#pragma once
#include <string>
#include <unordered_map>

#include "LevelLoader.h"

namespace Resources
{
	// ���������� ��������� ���� (��������, ���������, �������...)
	class ResourceManager
	{
	private:
		ResourceManager() {}
		ResourceManager(const ResourceManager& instance) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;
	public:
		static ResourceManager& Instance()
		{
			static ResourceManager instance;
			return instance;
		}
		
		// ��������� �������� �������� ����
		void Init();

		// ���������� ��� �������
		void Deinit();
	};
}
