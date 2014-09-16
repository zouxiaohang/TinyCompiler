#include "KeyWord.h"

namespace TinyCompiler{
	std::shared_ptr<KeyWordDict> KeyWordDictInstance::pInstance = nullptr;

	std::shared_ptr<KeyWordDict> KeyWordDictInstance::getInstance(){
		if (!pInstance){
			pInstance = std::make_shared<KeyWordDict>();
			pInstance->insert({ "break" });
			pInstance->insert({ "case" });
			pInstance->insert({ "char" });
			pInstance->insert({ "const" });
			pInstance->insert({ "continue" });
			pInstance->insert({ "default" });
			pInstance->insert({ "do" });
			pInstance->insert({ "double" });
			pInstance->insert({ "else" });
			pInstance->insert({ "enum" });
			pInstance->insert({ "float" });
			pInstance->insert({ "for" });
			pInstance->insert({ "if" });
			pInstance->insert({ "int" });
			pInstance->insert({ "long" });
			pInstance->insert({ "return" });
			pInstance->insert({ "short" });
			pInstance->insert({ "signed" });
			pInstance->insert({ "static" });
			pInstance->insert({ "struct" });
			pInstance->insert({ "switch" });
			pInstance->insert({ "typedef" });
			pInstance->insert({ "union" });
			pInstance->insert({ "unsigned" });
			pInstance->insert({ "void" });
			pInstance->insert({ "while" });
		}
		return pInstance;
	}
}