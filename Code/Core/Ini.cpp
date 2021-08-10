#include "Ini.h"

namespace 
{
	const std::string FILE_SETTINGS = "Config/Settings.ini";
}

namespace Core
{
//-----------------------------------------------------------------
Ini::Ini()
{
	m_filePath = FILE_SETTINGS;

	std::ifstream settingFile(m_filePath);
	if (!settingFile.is_open())
	{
		std::ofstream createSettingFile(m_filePath);
		createSettingFile.close();
	}
	settingFile.close();

	boost::property_tree::ini_parser::read_ini(FILE_SETTINGS, m_pTree);
}
//-----------------------------------------------------------------
Ini::Ini(std::string& filePath)
{
	m_filePath = filePath;

	std::ifstream settingFile(m_filePath);
	if (!settingFile.is_open())
	{
		std::ofstream createSettingFile(m_filePath);
		createSettingFile.close();
	}
	settingFile.close();

	boost::property_tree::ini_parser::read_ini(filePath, m_pTree);
}
//-----------------------------------------------------------------
Ini::~Ini()
{
	m_pTree.clear();
}
//-----------------------------------------------------------------
int Ini::GetIntValue(std::string propertyName)
{
	return m_pTree.get<int>(propertyName);
}
//-----------------------------------------------------------------
float Ini::GetFloatValue(std::string propertyName)
{
	return m_pTree.get<float>(propertyName);
}
//-----------------------------------------------------------------
std::string Ini::GetStringValue(std::string propertyName)
{
	return m_pTree.get<std::string>(propertyName);
}
//-----------------------------------------------------------------
void Ini::SetIntValue(std::string propertyName, int value)
{
	m_pTree.put(propertyName, value);
	boost::property_tree::ini_parser::write_ini(m_filePath, m_pTree);
}
//-----------------------------------------------------------------
void Ini::SetFloatValue(std::string propertyName, float value)
{
	m_pTree.put(propertyName, value);
	boost::property_tree::ini_parser::write_ini(m_filePath, m_pTree);
}
//-----------------------------------------------------------------
void Ini::SetStringValue(std::string propertyName, std::string value)
{
	m_pTree.put(propertyName, value);
	boost::property_tree::ini_parser::write_ini(m_filePath, m_pTree);
}
//-----------------------------------------------------------------
}