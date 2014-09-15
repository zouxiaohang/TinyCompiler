#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>

#include "Scanner.h"

namespace TinyCompile{
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

	void Scanner::handleBegin(std::string& tokenName){
		if (std::isdigit(*(this->citer))){//是数字
			this->phrase_ = ScanPhrase::IN_INTEGER;
		}else if(std::isalpha(*(this->citer))){//是字母
			this->phrase_ = ScanPhrase::IN_VARIALBE;
		}else if (*(this->citer) == '\"' || *(this->citer) == '\''){//是双引号或单引号
			this->phrase_ = ScanPhrase::IN_STRING;
		}
		else{
			this->phrase_ = ScanPhrase::IN_DELIMITER;
		}
		tokenName += *(this->citer);
		++(this->citer);
	}
	void Scanner::handleDelimiter(std::string& tokenName){
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
		size_t location = 1;

		skipBlank(this->citer, location);//跳过前导空白
		while (this->citer != code_.cend() && *(this->citer) != EOF){
			switch (this->phrase_){
			case ScanPhrase::BEGIN:
				handleBegin(tokenName);
				break;
			case ScanPhrase::IN_DELIMITER:
				handleDelimiter(tokenName);
				break;
			case ScanPhrase::IN_INTEGER:
				handleInteger();
			case ScanPhrase::IN_KEYWORD:
				handleKeyWord();
				break;
			case ScanPhrase::IN_REAL:
				handleReal();
				break;
			case ScanPhrase::IN_STRING:
				handleString();
				break;
			case ScanPhrase::IN_VARIALBE:
				handleVariable();
				break;

			case ScanPhrase::END:
				return handleEnd(tokenName, tokenAttr, location);
			}
		}
	}
}