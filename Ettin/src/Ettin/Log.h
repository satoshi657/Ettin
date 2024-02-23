#pragma once
#include<memory>
#include "spdlog/spdlog.h"
#include"Core.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ettin
{

	class ETTIN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define ET_CORE_ERROR(...)    ::Ettin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ET_CORE_WARN(...)     ::Ettin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ET_CORE_INFO(...)     ::Ettin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ET_CORE_TRACE(...)    ::Ettin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ET_CORE_FATAL(...)    ::Ettin::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define ET_ERROR(...)         ::Ettin::Log::GetClientLogger()->error(__VA_ARGS__)
#define ET_WARN(...)          ::Ettin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ET_INFO(...)          ::Ettin::Log::GetClientLogger()->info(__VA_ARGS__)
#define ET_TRACE(...)         ::Ettin::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ET_FATAL(...)         ::Ettin::Log::GetClientLogger()->fatal(__VA_ARGS__)


