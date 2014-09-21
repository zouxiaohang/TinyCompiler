#ifndef _KEYWORD_H_
#define _KEYWORD_H_

#include <memory>
#include <set>
#include <string>
#include <utility>

namespace TinyCompiler{

	//定义代码的关键字
	enum class KeyWord{
		BREAK,
		CASE,
		CHAR,
		CONST,
		CONTINUE,
		DEFAULT,
		DO,
		DOUBLE,
		ELSE,
		ENUM,
		FLOAT,
		FOR,
		IF,
		INT,
		LONG,
		RETURN,
		SHORT,
		SIGNED,
		STATIC,
		STRUCT,
		SWITCH,
		TYPEDEF,
		UNION,
		UNSIGNED,
		VOID,
		WHILE
	};

	typedef std::set<std::string> KeyWordDict;
	class KeyWordDictInstance{
	private:
		static std::shared_ptr<KeyWordDict> pInstance;
	public:
		static std::shared_ptr<KeyWordDict> getInstance();
	};
}

#endif