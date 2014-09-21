#ifndef _DEFINE_SQUENCE_STATEMENT_NODE_H_
#define _DEFINE_SQUENCE_STATEMENT_NODE_H_

#include "SquenceStatementNode.h"

namespace TinyCompiler{

	//the define statement class
	class DefineSquenceStatementNode :public SquenceStatementNode{
	public:
		virtual void printNodeKind(){ std::cout << "DefineSquenceStatementNode" << std::endl; }
	};

	StatementNodeKind DefineSquenceStatementNode::kind_ = StatementNodeKind::DEFINESQUENCESTATEMENTNODE;
}

#endif