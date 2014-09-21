#ifndef _STATEMENT_NODE_H_
#define _STATEMENT_NODE_H_

#include <string>

namespace TinyCompiler{

	//Óï¾ä¿éµÄ»ùÀà
	class StatementNode{
	public:
		std::string name;
	public:
		virtual ~StatementNode();
	};
}

#endif