#include <iostream>
#include <fstream>

#include "Profiler\Profiler.h"
#include "Scanner\Scanner.h"
#include "StatementNode\StatementNodeInclude.h"

using namespace std;
using namespace std::chrono;

int main(){
	using namespace TinyCompiler;
	StatementNode sn;

	LoopStatementNode lsn;
	FORLoopStatementNode flsn;
	WhileLoopStatementNode wlsn;

	CheckStatementNode csn;
	IFCheckStatementNode icsn;

	SquenceStatementNode ssn;
	ArithmeticSquenceStatementNode arssn;
	AssignSquenceStatementNode asssn;
	DefineSquenceStatementNode dssn;

	std::vector<StatementNode*> svec;
	svec.push_back(&sn);
	svec.push_back(&lsn);
	svec.push_back(&flsn);
	svec.push_back(&wlsn);
	svec.push_back(&csn);
	svec.push_back(&icsn);
	svec.push_back(&ssn);
	svec.push_back(&arssn);
	svec.push_back(&asssn);
	svec.push_back(&dssn);

	for (const auto& node : svec){
		node->printNodeKind();
	}
	
	//typedef TinyCompiler::Profiler::ProfilerInstance Profiler;
	//TinyCompiler::Scanner s("C:\\Users\\zxh\\Desktop\\nginx.c"); 
	//TinyCompiler::Token tok;

	//ofstream out("C:\\Users\\zxh\\Desktop\\output.c",
	//	ostream::out | ofstream::trunc);


	//Profiler::start();
	//while ((tok = s.getNextToken())){
	//	cout << tok.getName() << endl;
	//	//tok.dumpToken();
	//}
	//Profiler::finish();
	//Profiler::dumpDuringTime();
	//out.close();
	system("pause");
	return 0;
}