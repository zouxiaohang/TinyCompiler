#ifndef _PROFILER_H_
#define _PROFILER_H_

#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>
#include <ratio>
#include <utility>

namespace TinyCompiler{

	namespace Profiler{
		//static std::chrono::steady_clock::time_point startTime;
		//static std::chrono::steady_clock::time_point finishTime;
		class ProfilerInstance{
		public:
			typedef std::chrono::steady_clock SteadyClock;
			typedef SteadyClock::time_point TimePoint;
		private:
			static TimePoint startTime;
			static TimePoint finishTime;
		public:
			static void start();
			static void finish();
			static void dumpDuringTime(std::ostream& os = std::cout);
		};
	}
}

#endif