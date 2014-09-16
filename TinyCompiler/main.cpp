#include <iostream>

#include "Profiler.h"
#include "Scanner.h"

using namespace std;
using namespace std::chrono;

int main(){
	typedef TinyCompiler::Profiler::ProfilerInstance Profiler;
	TinyCompiler::Scanner s("C:\\Users\\zxh\\Desktop\\nginx.c"); 
	TinyCompiler::Token tok;
	Profiler::start();
	while ((tok = s.getNextToken())){
		cout << tok.getName() << endl;
		//tok.dumpToken();
	}
	Profiler::finish();
	Profiler::dumpDuringTime();
	system("pause");
	return 0;
}