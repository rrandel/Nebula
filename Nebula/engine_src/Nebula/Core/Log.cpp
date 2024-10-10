#include "nbpch.hpp"
#include "Log.hpp"

#include <filesystem>

namespace Nebula {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    const std::string Log::LOG_FILE_PREFIX = "log/Nebula";
    const std::string Log::LOG_FILE_EXTENSION = ".log";
    const size_t Log::MAX_LOG_FILES = 5; // Maximum number of log files

    void Log::Init()
    {
        if (!std::filesystem::exists("logs")) {
            std::filesystem::create_directory("logs");
        }

        std::vector<spdlog::sink_ptr> logSinks;

        logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

        auto rotatingSink = CreateRotatingFileSink();
        logSinks.emplace_back(rotatingSink);

        logSinks[0]->set_pattern("%^[%T] [%l] [%n] [%s:%#] %v%$");
        logSinks[1]->set_pattern(R"({"timestamp":"%T","level":"%l","logger":"%n","file":"%s","line":%#,"message":"%v"})");

        s_CoreLogger = std::make_shared<spdlog::logger>("NEBULA", logSinks.begin(), logSinks.end());
        spdlog::register_logger(s_CoreLogger);

        s_ClientLogger = std::make_shared<spdlog::logger>("APPLICATION", logSinks.begin(), logSinks.end());
        spdlog::register_logger(s_ClientLogger);

#ifdef NB_DEBUG
        // Debug configuration
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger->set_level(spdlog::level::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);
#elif defined(NB_RELEASE)
        // Release configuration
        s_CoreLogger->set_level(spdlog::level::warn);
        s_ClientLogger->set_level(spdlog::level::warn);
        s_CoreLogger->flush_on(spdlog::level::warn);
        s_ClientLogger->flush_on(spdlog::level::warn);
#elif defined(NB_DIST)
        // Distribution configuration
        s_CoreLogger->set_level(spdlog::level::err);
        s_ClientLogger->set_level(spdlog::level::err);
        s_CoreLogger->flush_on(spdlog::level::err);
        s_ClientLogger->flush_on(spdlog::level::err);
#endif
    }

    std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> Log::CreateRotatingFileSink()
    {
        auto rotatingSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(LOG_FILE_PREFIX + LOG_FILE_EXTENSION, 1048576 * 5, MAX_LOG_FILES);

        rotatingSink->set_pattern(R"({"timestamp":"%Y-%m-%d %H:%M:%S","level":"%l","logger":"%n","file":"%s","line":%#,"message":"%v"})");

        return rotatingSink;
    }

    void Log::SetCoreLogLevel(spdlog::level::level_enum level)
    {
        s_CoreLogger->set_level(level);
    }

    void Log::SetClientLogLevel(spdlog::level::level_enum level)
    {
        s_ClientLogger->set_level(level);
    }

}
