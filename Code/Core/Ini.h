#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace Core
{
	// Класс для работы с ini файлами
	class Ini
	{
		boost::property_tree::ptree m_configTree;
		std::string					m_filePath;

	public:
		Ini();
		Ini(const std::string& filePath);

		~Ini();

		// Получить значение из Property Tree
		template <typename T> T GetValue(const std::string& propertyName) 
		{
			return m_configTree.get<T>(propertyName);
		}

		// Записать значение в Property Tree
		template <typename T> void SetValue(const std::string& propertyName, const T value)
		{
			m_configTree.put(propertyName, value);
		}
	};
}
