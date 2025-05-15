#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Rhy
{
	class RHY_API Log
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

/*************************
 *Macros for Core logging*
 ************************/
#define R_CORE_TRACE(...)    ::Rhy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define R_CORE_INFO(...)     ::Rhy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define R_CORE_WARN(...)     ::Rhy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define R_CORE_ERROR(...)    ::Rhy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define R_CORE_CRITICAL(...) ::Rhy::Log::GetCoreLogger()->critical(__VA_ARGS__)

 /***************************
  *Macros for Client logging*
  **************************/
#define R_TRACE(...)         ::Rhy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define R_INFO(...)          ::Rhy::Log::GetClientLogger()->info(__VA_ARGS__)
#define R_WARN(...)          ::Rhy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define R_ERROR(...)         ::Rhy::Log::GetClientLogger()->error(__VA_ARGS__)
#define R_CRITICAL(...)      ::Rhy::Log::GetClientLogger()->critical(__VA_ARGS__)



