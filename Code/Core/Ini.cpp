#include "Ini.h"

namespace 
{
	const std::string FILE_SETTINGS = "Config/Settings.ini";
}

namespace Core
{
//-----------------------------------------------------------------
Ini::Ini():Ini(FILE_SETTINGS) {}
//-----------------------------------------------------------------
Ini::Ini(const std::string& filePath)
{
	m_filePath = filePath;

	std::ifstream iniFile(m_filePath);
	if (!iniFile.is_open())
	{
		std::ofstream newIniFile(m_filePath);
		newIniFile.close();
	}
	iniFile.close();

	boost::property_tree::ini_parser::read_ini(filePath, m_pTree);
}
//-----------------------------------------------------------------
Ini::~Ini()
{
	m_pTree.clear();
}
//-----------------------------------------------------------------
int Ini::GetIntValue(const std::string& propertyName)
{
	return m_pTree.get<int>(propertyName);
}
//-----------------------------------------------------------------
float Ini::GetFloatValue(const std::string& propertyName)
{
	return m_pTree.get<float>(propertyName);
}
//-----------------------------------------------------------------
std::string Ini::GetStringValue(const std::string& propertyName)
{
	return m_pTree.get<std::string>(propertyName);
}
//-----------------------------------------------------------------
void Ini::SetIntValue(const std::string& propertyName, int value)
{
	m_pTree.put(propertyName, value);
}
//-----------------------------------------------------------------
void Ini::SetFloatValue(const std::string& propertyName, float value)
{
	m_pTree.put(propertyName, value);
}
//-----------------------------------------------------------------
void Ini::SetStringValue(const std::string& propertyName, const std::string& value)
{
	m_pTree.put(propertyName, value);
}
//-----------------------------------------------------------------
void Ini::WriteChangesToINIFile()
{
	boost::property_tree::ini_parser::write_ini(m_filePath, m_pTree);
}
//-----------------------------------------------------------------
}