#include "Profiler.h"

namespace TinyCompiler{
	namespace Profiler{

		void ProfilerInstance::start(){
			startTime = SteadyClock::now(); 
		}
		void ProfilerInstance::finish(){
			finishTime = SteadyClock::now();
		}
		void ProfilerInstance::dumpDuringTime(std::ostream& os){
			typedef std::chrono::duration<double> DurationTime;
			DurationTime duringTime =
				std::chrono::duration_cast<DurationTime>(finishTime - startTime);
			os << "total " << duringTime.count() * 1000 << " miliseconds" << std::endl;
		}
	}
}