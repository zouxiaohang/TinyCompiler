#ifndef _LOOP_STATEMENT_H_
#define _LOOP_STATEMENT_H_

#include "../StatementNode.h"
namespace TinyCompiler{

	//loop statement class
	class LoopStatementNode : public StatementNode{
	public:
		virtual void printNode(){ std::cout << "LoopStatementNode" << std::endl; }
        StatementNodeKind LoopStatementNode::kind_ = StatementNodeKind::LOOPSTATEMENTNODE;
    };
}
#endif