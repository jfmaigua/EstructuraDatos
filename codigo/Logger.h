#pragma once
#include <iostream>
#include <thread> 
#include <mutex>
#include <string>

enum class LoggerLevel {
    info,
    error,
    debug
};

class Logger {
public:
    static Logger* obtenerInstancia() {
        if (!instancia) {
            std::mutex _mutex;
            std::lock_guard<std::mutex> _lock(_mutex);

            if (!instancia) {
                instancia = new Logger;
            }
        }

        return instancia;
    }

    void info(std::string const& message);
    void error(std::string const& message);
    void debug(std::string const& message);
    void log(std::string const& message, LoggerLevel level);

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
	static Logger* instancia;
};