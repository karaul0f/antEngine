#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace Core
{
	class Ini
	{
		boost::property_tree::ptree m_pTree;
		std::string					m_filePath;

	public:
		Ini();
		Ini(std::string& filePath);

		~Ini();

		// Получить значение из заданного ini файла
		int GetIntValue(std::string propertyName);
		float GetFloatValue(std::string propertyName);
		std::string GetStringValue(std::string propertyName);

		// Записать значение в ini файл
		void SetIntValue(std::string propertyName, int value);
		void SetFloatValue(std::string propertyName, float value);
		void SetStringValue(std::string propertyName, std::string value);
	};
}
