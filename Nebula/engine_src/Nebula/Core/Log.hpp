#pragma once

#include "Nebula/Core/Base.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#pragma warning(pop)

namespace Nebula {

    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

        static void SetCoreLogLevel(spdlog::level::level_enum level);
        static void SetClientLogLevel(spdlog::level::level_enum level);

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

        static std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> CreateRotatingFileSink();

        static const std::string LOG_FILE_PREFIX;
        static const std::string LOG_FILE_EXTENSION;
        static const size_t MAX_LOG_FILES;
    };

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
    return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
    return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
    return os << glm::to_string(quaternion);
}

#define NB_CORE_WARN(...)    ::Nebula::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NB_CORE_INFO(...)    ::Nebula::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NB_CORE_ERROR(...)   ::Nebula::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NB_CORE_TRACE(...)   ::Nebula::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define NB_INFO(...)         ::Nebula::Log::GetClientLogger()->info(__VA_ARGS__)
#define NB_WARN(...)         ::Nebula::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NB_ERROR(...)        ::Nebula::Log::GetClientLogger()->error(__VA_ARGS__)
#define NB_TRACE(...)        ::Nebula::Log::GetClientLogger()->trace(__VA_ARGS__)