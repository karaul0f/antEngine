#pragma once
#include <string>

#define INFO(msg) Core::Logger::Instance().Info(msg)
#define ERROR(msg) Core::Logger::Instance().Error(msg)
#define WARNING(msg) Core::Logger::Instance().Warning(msg)

namespace Core
{
	// Класс для вывода отладочной информации
	class Logger
	{
	private:
		Logger() {}
		Logger(const Logger& instance) = delete;
		Logger& operator=(const Logger&) = delete;

		void Log(const std::string& message, const std::string& messageType);
	public:
		static Logger& Instance()
		{
			static Logger instance;
			return instance;
		}
		
		// Вывести отладочную информацию по стандартному пути
		void Info(const std::string &message);

		// Вывести информацию об ошибке в стандартный файл
		void Error(const std::string &message);

		// Вывести информацию о предупрежении в стандартный файл
		void Warning(const std::string &message);
	};
}
