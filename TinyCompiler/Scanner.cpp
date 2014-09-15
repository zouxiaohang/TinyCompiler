#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>

#include "KeyWord.h"
#include "Scanner.h"

extern TinyCompiler::KeyWordDict keyWordDict;

namespace TinyCompiler{
	void Scanner::setPhrase(const ScanPhrase phrase){
		this->phrase_ = phrase;
	}

	Scanner::ScanPhrase Scanner::getPhrase() const{
		return this->phrase_;
	}

	void Scanner::setFileName(const std::string& fileName){
		this->fileName_ = fileName;
	}

	std::string Scanner::getFileName() const{
		return this->fileName_;
	}

	void Scanner::clear(){
		this->code_ = "";
		this->citer = this->code_.cbegin();
		this->fileName_ = "";
		this->phrase_ = ScanPhrase::BEGIN;
	}

	bool Scanner::openFile(){
		assert(!(this->fileName_.empty()));

		std::ifstream in(this->fileName_);
		if (in){
			in.seekg(0, in.end);
			size_t length = in.tellg();
			in.seekg(0, in.beg);
			//调整code_的空间以完全容纳全部源码
			this->code_.resize(length);
			in.read(&(this->code_[0]), this->code_.size());
			this->citer = code_.cbegin();
			in.close();
			return true;
		}
		return false;
	}

	void Scanner::skipBlank(std::string::const_iterator& cit, size_t& location){
		for (; *cit != EOF; ){
			if (std::isblank(*cit) || *cit == '\n'){
				if (*cit == '\n'){
					++location;
				}
				++cit;
			}
			else{
				break;
			}
		}
	}

	void Scanner::handleBegin(std::string& tokenName, TokenAttr& tokenAttr){
		if (std::isdigit(*(this->citer))){//是数字
			this->phrase_ = ScanPhrase::IN_INTEGER;
		}else if(std::isalpha(*(this->citer))){//是字母
			this->phrase_ = ScanPhrase::IN_VARIALBE;
		}else if (*(this->citer) == '\"' || *(this->citer) == '\''){//是双引号或单引号
			this->phrase_ = ScanPhrase::IN_STRING;
		}else{
			this->phrase_ = ScanPhrase::IN_DELIMITER;
		}
		tokenName += *(this->citer);
		++(this->citer);
	}
	void Scanner::handleString(std::string& tokenName, TokenAttr& tokenAttr){
		if (*(this->citer) != '\"' || *(this->citer) != '\''){
			tokenName += *(this->citer);
			++(this->citer);
			this->phrase_ = ScanPhrase::IN_STRING;
		}
		else{
			tokenName += *(this->citer);
			++(this->citer);
			tokenAttr = TokenAttr::STRING;
			this->phrase_ = ScanPhrase::END;
		}
	}
	void Scanner::handleReal(std::string& tokenName, TokenAttr& tokenAttr){
		if (isdigit(*(this->citer))){//任然是数字
			tokenName += *(this->citer);
			++(this->citer);
			this->phrase_ = ScanPhrase::IN_REAL;
		}else{
			tokenAttr = TokenAttr::REAL;
			this->phrase_ = ScanPhrase::END;
		}
	}
	void Scanner::handleInteger(std::string& tokenName, TokenAttr& tokenAttr){
		if (isdigit(*(this->citer))){//任然是数字
			tokenName += *(this->citer);
			++(this->citer);
			this->phrase_ = ScanPhrase::IN_INTEGER;
		}else if (*(this->citer) == '.'){//出现小数点
			tokenName += *(this->citer);
			++(this->citer);
			this->phrase_ = ScanPhrase::IN_REAL;
		}else{
			tokenAttr = TokenAttr::INTEGER;
			this->phrase_ = ScanPhrase::END;
		}
	}
	void Scanner::handleVariable(std::string& tokenName, TokenAttr& tokenAttr){
		if (std::isalpha(*(this->citer))){//任然是字母
			tokenName += *(this->citer);
			++(this->citer);
			this->phrase_ = ScanPhrase::IN_VARIALBE;
		}else{
			if (keyWordDict.count(tokenName) != 0){//变量为关键字
				this->phrase_ = ScanPhrase::IN_KEYWORD;
			}else{
				tokenAttr = TokenAttr::VARIABLE;
				this->phrase_ = ScanPhrase::END;
			}
		}
	}
	void Scanner::handleKeyWord(std::string& tokenName, TokenAttr& tokenAttr){
		tokenAttr = TokenAttr::KEYWORD;
		this->phrase_ = ScanPhrase::END;
	}
	void Scanner::handleDelimiter(std::string& tokenName, TokenAttr& tokenAttr){
		tokenAttr = TokenAttr::DELIMITER;
		this->phrase_ = ScanPhrase::END;
	}

	Token Scanner::handleEnd(std::string& name, 
							const TokenAttr tokenAttr, 
							const size_t location){
		return Token(name, tokenAttr, this->fileName_, location);
	}

	Token Scanner::getNextToken(){
		assert(openFile());

		this->phrase_ = ScanPhrase::BEGIN;
		std::string tokenName;
		TokenAttr tokenAttr = TokenAttr::UNKNOWN;

		skipBlank(this->citer, this->location);//跳过前导空白
		while (this->citer != code_.cend() && *(this->citer) != EOF){
			switch (this->phrase_){
			case ScanPhrase::BEGIN:
				handleBegin(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_DELIMITER:
				handleDelimiter(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_INTEGER:
				handleInteger(tokenName, tokenAttr);
			case ScanPhrase::IN_KEYWORD:
				handleKeyWord(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_REAL:
				handleReal(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_STRING:
				handleString(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_VARIALBE:
				handleVariable(tokenName, tokenAttr);
				break;

			case ScanPhrase::END:
				return handleEnd(tokenName, tokenAttr, this->location);
			}
		}
		return Token("", TokenAttr::UNKNOWN, "", -1);
	}
}