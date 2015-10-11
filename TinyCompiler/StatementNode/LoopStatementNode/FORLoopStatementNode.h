#ifndef _FOR_LOOP_STATEMENT_H_
#define _FOR_LOOP_STATEMENT_H_

#include "LoopStatementNode.h"

namespace TinyCompiler{

	//for loop statement class
	class FORLoopStatementNode : public LoopStatementNode{
	public:
		virtual void printNode(){ std::cout << "FORLoopStatementNode" << std::endl; }
        StatementNodeKind FORLoopStatementNode::kind_ = StatementNodeKind::FORLOOPSTATEMENTNODE;
    };
}
#endif