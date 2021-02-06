#pragma once
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>

namespace utils {
	inline static std::string getFormattedTime(std::string const &format) {
		std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
		time_t in_time_t = std::chrono::system_clock::to_time_t(now);
		std::tm bt{};

#if defined(_MSC_VER)
		localtime_s(&bt, &in_time_t);
#else
		static std::mutex mtx;
		std::lock_guard<std::mutex> lock(mtx);
		bt = *std::localtime(&timer);
#endif

		char output[100];
		std::strftime(output, sizeof(output), format.c_str(), &bt);

		return std::string(output);
	}

	static inline std::string getFormattedTime() {
		return getFormattedTime("%d-%m-%Y-%X");
	}
};