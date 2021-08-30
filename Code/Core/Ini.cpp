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

	boost::property_tree::ini_parser::read_ini(filePath, m_configTree);
}
//-----------------------------------------------------------------
Ini::~Ini()
{
	boost::property_tree::ini_parser::write_ini(m_filePath, m_configTree);
	m_configTree.clear();
}
//-----------------------------------------------------------------
}