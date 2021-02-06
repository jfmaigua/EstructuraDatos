#include "Logger.h"
#include "utils.h"

Logger* Logger::instancia = nullptr;

void Logger::info(std::string const& message) {
	log(message, LoggerLevel::info);
}

void Logger::error(std::string const& message) {
	log(message, LoggerLevel::error);
}

void Logger::debug(std::string const& message) {
	log(message, LoggerLevel::debug);
}

void Logger::log(std::string const& message, LoggerLevel level) {
	std::string label = (level == LoggerLevel::debug 
		? "DEBUG" : (level == LoggerLevel::info 
			? "INFO" : (level == LoggerLevel::error 
				? "ERROR" : "MESSAGE")));

	std::cout << "[" << label << "][" << utils::getFormattedTime() << "]" 
			  << " " << message << std::endl;
}