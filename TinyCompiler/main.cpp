#include <iostream>
#include <fstream>

#include "Profiler.h"
#include "Scanner.h"

using namespace std;
using namespace std::chrono;

int main(){
	typedef TinyCompiler::Profiler::ProfilerInstance Profiler;
	TinyCompiler::Scanner s("C:\\Users\\zxh\\Desktop\\lmem.c"); 
	TinyCompiler::Token tok;

	ofstream out("C:\\Users\\zxh\\Desktop\\output.c",
		ostream::out | ofstream::trunc);


	Profiler::start();
	while ((tok = s.getNextToken())){
		//cout << tok.getName() << endl;
		tok.dumpToken(out);
	}
	Profiler::finish();
	Profiler::dumpDuringTime();
	out.close();
	system("pause");
	return 0;
}