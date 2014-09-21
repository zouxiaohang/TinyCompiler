#ifndef _ASSIGN_SQUENCE_STATEMENT_NODE_H_
#define _ASSIGN_SQUENCE_STATEMENT_NODE_H_

#include "SquenceStatementNode.h"

namespace TinyCompiler{

	//the assign statement class
	class AssignSquenceStatementNode :public SquenceStatementNode{
	public:
		virtual void printNodeKind(){ std::cout << "AssignSquenceStatementNode" << std::endl; }
	};

	StatementNodeKind AssignSquenceStatementNode::kind_ = StatementNodeKind::ASSIGNSQUENCESTATEMENTNODE;
}

#endif