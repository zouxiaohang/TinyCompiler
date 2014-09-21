#include <cassert>

#include "TokenAttr.h"

namespace TinyCompiler{
	
	std::shared_ptr<TokenAttrDictInstance::TokenAttrDict> 
		TokenAttrDictInstance::pInstance = nullptr;

	std::shared_ptr<TokenAttrDictInstance::TokenAttrDict> 
		TokenAttrDictInstance::getInstance(){
			if (!pInstance){
				pInstance = std::make_shared<TokenAttrDict>();
				pInstance->insert({ TokenAttr::KEYWORD, "KEYWORD" });
				pInstance->insert({ TokenAttr::DELIMITER, "DELIMITER" });
				pInstance->insert({ TokenAttr::INTEGER, "INTEGER" });
				pInstance->insert({ TokenAttr::REAL, "REAL" });
				pInstance->insert({ TokenAttr::STRING, "STRING" });
				pInstance->insert({ TokenAttr::VARIABLE, "VARIABLE" });
				pInstance->insert({ TokenAttr::UNKNOWN, "UNKNOWN" });
			}

			return pInstance;
		}

}