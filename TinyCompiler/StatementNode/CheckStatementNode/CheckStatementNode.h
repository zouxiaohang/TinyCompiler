#ifndef _CHECK_STATEMENT_H_
#define _CHECK_STATEMENT_H_

#include "../StatementNode.h"
namespace TinyCompiler{

	//check statement class
	class CheckStatementNode : public StatementNode{
	public:
		virtual void printNode(){ std::cout << "CheckStatementNode" << std::endl; }
	};

	StatementNodeKind CheckStatementNode::kind_ = StatementNodeKind::CHECKSTATEMENTNODE;
}

#endif