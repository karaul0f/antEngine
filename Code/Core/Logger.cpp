#include "Logger.h"
#include <fstream>

namespace Core
{
//-----------------------------------------------------------------
void Logger::Log(const std::string& message, const std::string &messageType = std::string())
{
	std::ofstream fout("Log.txt", std::ios::app); 
	fout << "[" << messageType << "] " << message << std::endl;
	fout.close(); 
}
//-----------------------------------------------------------------
void Logger::Info(const std::string& message)
{
	Log(message, "Info");
}
//-----------------------------------------------------------------
void Logger::Error(const std::string& message)
{
	Log(message, "Error");
}
//-----------------------------------------------------------------
void Logger::Warning(const std::string& message)
{
	Log(message, "Warning");
}
//-----------------------------------------------------------------
}
