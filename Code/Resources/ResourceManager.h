

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
	};
}
