#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <iostream>
#include <string>

#include "TokenAttr.h"

namespace TinyCompiler{

	//词素类
	class Token{
	private:
		//词素的名字
		std::string name_;
		//词素的属性
		TokenAttr tokenAttr_;
		//词素所在的文件
		std::string fileName_;
		//文件中的位置
		size_t location_;

	public:
		Token() 
			:name_(""), tokenAttr_(TokenAttr::UNKNOWN), fileName_(""), location_(0){}
		Token(std::string name, 
			TokenAttr tokenAttr,
			std::string fileName, 
			size_t location) 
			:name_(name), tokenAttr_(tokenAttr), fileName_(fileName), location_(location){}

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