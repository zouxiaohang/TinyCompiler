#include <set>
#include <string>

#include "KeyWord.h"

namespace TinyCompiler{
	typedef std::set<std::string> KeyWordDict;
	KeyWordDict keyWordDict = {
		{ "break" },
		{ "case" },
		{ "char" },
		{ "const" },
		{ "continue" },
		{ "default" },
		{ "do" },
		{ "double" },
		{ "else" },
		{ "enum" },
		{ "float" },
		{ "for" },
		{ "if" },
		{ "int" },
		{ "long" },
		{ "return" },
		{ "short" },
		{ "signed" },
		{ "static" },
		{ "struct" },
		{ "switch" },
		{ "typedef" },
		{ "union" },
		{ "unsigned" },
		{ "void" },
		{ "while" },
	};
}