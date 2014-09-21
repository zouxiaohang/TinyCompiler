#ifndef _STATEMENT_NODE_H_
#define _STATEMENT_NODE_H_

#include <string>

namespace TinyCompiler{

	//the base class of the statement
	class StatementNode{
	public:
		std::string name;
	public:
		virtual ~StatementNode();
	};
}

#endif