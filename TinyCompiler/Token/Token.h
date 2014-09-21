#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <iostream>
#include <string>

#include "TokenAttr.h"

namespace TinyCompiler{

	class Token{
	private:
		std::string name_;
		TokenAttr tokenAttr_;
		std::string fileName_;
		size_t location_;

	public:
		Token() 
			:name_(""), tokenAttr_(TokenAttr::UNKNOWN), fileName_(""), location_(0){}
		Token(std::string name, 
			TokenAttr tokenAttr,
			std::string fileName, 
			size_t location) 
			:name_(name), tokenAttr_(tokenAttr), fileName_(fileName), location_(location){}

		operator bool(){
			if (tokenAttr_ == TokenAttr::UNKNOWN)
				return false;
			return true;
		}

		void setName(const std::string& name);
		std::string getName() const;
		void setTokenAttr(const TokenAttr tokenAttr);
		TokenAttr getTokenAttr() const;
		void setFileName(const std::string& fileName);
		std::string getFileName() const;
		void setLocation(const size_t location);
		size_t getLocation() const;

		void dumpToken(std::ostream& os = std::cout) const;
	};
}

#endif