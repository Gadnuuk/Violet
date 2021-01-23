#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Violet
{
	class VIOLET_API Log
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

//Core Log Macros
#define VIOLET_CORE_TRACE(...)		::Violet::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VIOLET_CORE_LOG(...)		::Violet::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VIOLET_CORE_WARN(...)		::Violet::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VIOLET_CORE_ERROR(...)		::Violet::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VIOLET_CORE_FATAL(...)		::Violet::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define VIOLET_TRACE(...)			::Violet::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VIOLET_LOG(...)				::Violet::Log::GetClientLogger()->info(__VA_ARGS__)
#define VIOLET_WARN(...)			::Violet::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VIOLET_ERROR(...)			::Violet::Log::GetClientLogger()->error(__VA_ARGS__)
#define VIOLET_FATAL(...)			::Violet::Log::GetClientLogger()->fatal(__VA_ARGS__)

