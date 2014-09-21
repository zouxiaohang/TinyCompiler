#ifndef _SQUENCE_STATEMENT_H_
#define _SQUENCE_STATEMENT_H_

#include "../StatementNode.h"
namespace TinyCompiler{
	
	//squence statement class
	class SquenceStatementNode : public StatementNode{
	public:
		virtual void printNode(){ std::cout << "SquenceStatementNode" << std::endl; }
	};
}

#endif