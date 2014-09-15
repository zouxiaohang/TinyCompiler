#include <cassert>

#include "TokenAttr.h"

namespace TinyCompile{
	
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

	/*std::string TokenAttrDictInstance::getTokenAttrString(const TokenAttr attr) const{
		assert(pInstance);

		return (*pInstance)[attr];
	}*/
}