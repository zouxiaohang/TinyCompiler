#ifndef _STATEMENT_NODE_H_
#define _STATEMENT_NODE_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "StatementNodeAttr.h"

namespace TinyCompiler{

	//the base class of the statement
	class StatementNode{
	public:
		//std::string name;
		typedef std::shared_ptr<StatementNode> SNPtr;
		std::vector<SNPtr> nodes_;
		static StatementNodeKind kind_;
	public:
		virtual void printNodeKind(){ std::cout << "StatementNode" << std::endl; }
		virtual ~StatementNode(){};
	};

	StatementNodeKind StatementNode::kind_ = StatementNodeKind::STATEMENTNODE;
}

#endif