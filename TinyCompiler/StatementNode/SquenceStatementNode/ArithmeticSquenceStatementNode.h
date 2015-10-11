#ifndef _ARITHMETIC_SQUENCE_STATEMENT_NODE_H_
#define _ARITHMETIC_SQUENCE_STATEMENT_NODE_H_

#include "SquenceStatementNode.h"

namespace TinyCompiler{

	//the arithmetic statement class
	class ArithmeticSquenceStatementNode :public SquenceStatementNode{
	public:
		virtual void printNodeKind(){ std::cout << "ArithmeticSquenceStatementNode" << std::endl; }
        StatementNodeKind ArithmeticSquenceStatementNode::kind_ = StatementNodeKind::ARITHMETICSQUENCESTATEMENTNODE;
    };
}

#endif