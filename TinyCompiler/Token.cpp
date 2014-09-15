#include "Token.h"

namespace TinyCompile{
	void Token::setName(const std::string& name){
		this->name_ = name;
	}
	std::string Token::getName() const{
		return this->name_;
	}
	void Token::setTokenAttr(const TokenAttr tokenAttr){
		this->tokenAttr_ = tokenAttr;
	}
	TokenAttr Token::getTokenAttr() const{
		return this->tokenAttr_;
	}
	void Token::setFileName(const std::string& fileName){
		this->fileName_ = fileName;
	}
	std::string Token::getFileName() const{
		return this->fileName_;
	}
	void Token::setLocation(const size_t location){
		this->location_ = location;
	}
	size_t Token::getLocation() const{
		return this->location_;
	}

	void Token::dumpToken(std::ostream& os = std::cout) const{
		os << "Token: " << "{"
			<< "name = " << this->name_
			<< "attr = " << (*(TokenAttrDictInstance::getInstance()))[this->tokenAttr_]
			<< "file = " << this->fileName_
			<< "loc = " << this->location_
			<< "}" << std::endl;
	}
}