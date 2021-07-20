

namespace Resources
{
	// Управление ресурсами игры (загрузка, изменение, экспорт...)
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
		
		// Запускаем загрузку ресурсов игры
		void Init();
	};
}
