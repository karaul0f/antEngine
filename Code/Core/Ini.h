#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace Core
{
	// ����� ��� ������ � ini �������
	class Ini
	{
		boost::property_tree::ptree m_pTree;
		std::string					m_filePath;

	public:
		Ini();
		Ini(const std::string& filePath);

		~Ini();

		// �������� �������� �� Property Tree
		int GetIntValue(const std::string& propertyName);
		float GetFloatValue(const std::string& propertyName);
		std::string GetStringValue(const std::string& propertyName);

		// �������� �������� � Property Tree
		void SetIntValue(const std::string& propertyName, int value);
		void SetFloatValue(const std::string& propertyName, float value);
		void SetStringValue(const std::string& propertyName, const std::string& value);

	};
}
