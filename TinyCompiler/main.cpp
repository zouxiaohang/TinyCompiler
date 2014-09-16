#include "Scanner.h"

#include <iostream>

using namespace std;

int main(){

	TinyCompiler::Scanner s("C:\\Users\\zxh\\Desktop\\test.c");
	TinyCompiler::Token tok;
	while ((tok = s.getNextToken())){
		cout << tok.getName() << endl;
		//tok.dumpToken();
	}
	system("pause");
	return 0;
}