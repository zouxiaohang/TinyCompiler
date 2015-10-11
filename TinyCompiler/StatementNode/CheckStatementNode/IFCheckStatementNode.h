#ifndef _IF_CHECK_STATEMENT_H_
#define _IF_CHECK_STATEMENT_H_

#include "CheckStatementNode.h"

namespace TinyCompiler{

	//if check statement class
	class IFCheckStatementNode : public CheckStatementNode{
	public:
		virtual void printNode(){ std::cout << "IFCheckStatementNode" << std::endl; }
        StatementNodeKind IFCheckStatementNode::kind_ = StatementNodeKind::IFCHECKSTATEMENTNODE;
    };
}
#endif