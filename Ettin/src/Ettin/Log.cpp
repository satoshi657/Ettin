#include "Log.h"

namespace Ettin
{
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger = nullptr;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger = nullptr;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);

        s_CoreLogger = spdlog::stdout_color_mt("ETTIN");
        s_CoreLogger->set_level(spdlog::level::trace);
    }
}