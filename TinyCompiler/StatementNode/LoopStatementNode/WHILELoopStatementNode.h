#ifndef _WHILE_LOOP_STATEMENT_H_
#define _WHILE_LOOP_STATEMENT_H_

#include "LoopStatementNode.h"

namespace TinyCompiler{

	//while loop statement class
	class WhileLoopStatementNode : public LoopStatementNode{
	public:
		virtual void printNode(){ std::cout << "WhileLoopStatementNode" << std::endl; }
        StatementNodeKind WhileLoopStatementNode::kind_ = StatementNodeKind::WHILELOOPSTATEMENTNODE;
    };
}
#endif