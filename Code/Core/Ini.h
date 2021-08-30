#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace Core
{
	// ����� ��� ������ � ini �������
	class Ini
	{
		boost::property_tree::ptree m_configTree;
		std::string					m_filePath;

	public:
		Ini();
		Ini(const std::string& filePath);

		~Ini();

		// �������� �������� �� Property Tree
		template <typename T> T GetValue(const std::string& propertyName) 
		{
			return m_configTree.get<T>(propertyName);
		}

		// �������� �������� � Property Tree
		template <typename T> void SetValue(const std::string& propertyName, const T value)
		{
			m_configTree.put(propertyName, value);
		}
	};
}
