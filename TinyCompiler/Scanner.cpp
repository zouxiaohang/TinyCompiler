#include <cctype>
#include <fstream>
#include <iostream>

#include "KeyWord.h"
#include "Scanner.h"

//extern TinyCompiler::KeyWordDict keyWordDict;

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
		citer_ = this->code_.cbegin();
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
			citer_ = code_.cbegin();
			in.close();
			return true;
		}
		return false;
	}
	bool Scanner::isDoubleDelimter(const char ch){
		if (ch == '>' || ch == '+' || ch == '-' ||
			ch == '<' || ch == '=' || ch == '&' ||
			ch == '|')
			return true;
		return false;
	}
	void Scanner::skipBlank(){
		for (; citer_ != code_.cend() && *citer_ != EOF; ){
			if (std::isblank(*citer_) || *citer_ == '\n'){
				if (*citer_ == '\n'){
					++location_;
				}
				++citer_;
			}
			else{
				break;
			}
		}
	}

	void Scanner::handleBegin(std::string& tokenName, TokenAttr& tokenAttr){
		if (std::isdigit(*(citer_))){//是数字
			this->phrase_ = ScanPhrase::IN_INTEGER;
		}else if(std::isalpha(*(citer_)) || *citer_ == '_'){//是字母或下划线
			this->phrase_ = ScanPhrase::IN_VARIALBE;
		}else if (*(citer_) == '\"' || *(citer_) == '\''){//是双引号或单引号
			this->phrase_ = ScanPhrase::IN_STRING;
		}else{//其他情况下先视为单分隔符
			this->phrase_ = ScanPhrase::IN_SINGLEDELIMITER;
		}
		tokenName += *(citer_);
		++(citer_);
	}
	void Scanner::handleString(std::string& tokenName, TokenAttr& tokenAttr){
		if (*(citer_) != '\"' && *(citer_) != '\''){
			tokenName += *(citer_);
			++(citer_);
			this->phrase_ = ScanPhrase::IN_STRING;
		}
		else{
			tokenName += *(citer_);
			++(citer_);
			tokenAttr = TokenAttr::STRING;
			this->phrase_ = ScanPhrase::END;
		}
	}
	void Scanner::handleReal(std::string& tokenName, TokenAttr& tokenAttr){
		if (isdigit(*(citer_))){//任然是数字
			tokenName += *(citer_);
			++(citer_);
			this->phrase_ = ScanPhrase::IN_REAL;
		}else{
			tokenAttr = TokenAttr::REAL;
			this->phrase_ = ScanPhrase::END;
		}
	}
	void Scanner::handleInteger(std::string& tokenName, TokenAttr& tokenAttr){
		if (isdigit(*(citer_))){//任然是数字
			tokenName += *(citer_);
			++(citer_);
			this->phrase_ = ScanPhrase::IN_INTEGER;
		}else if (*(citer_) == '.'){//出现小数点
			tokenName += *(citer_);
			++(citer_);
			this->phrase_ = ScanPhrase::IN_REAL;
		}else{
			tokenAttr = TokenAttr::INTEGER;
			this->phrase_ = ScanPhrase::END;
		}
	}
	void Scanner::handleVariable(std::string& tokenName, TokenAttr& tokenAttr){
		if (std::isalpha(*(citer_)) || *citer_ == '_'){//任然是字母或下划线
			tokenName += *(citer_);
			++(citer_);
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
	void Scanner::handleSingleDelimiter(std::string& tokenName, TokenAttr& tokenAttr){
		if (isDoubleDelimter(*citer_)){//是双分隔符
			tokenName += *citer_;
			++citer_;
			this->phrase_ = ScanPhrase::IN_DOUBLEDELIMITER;
		}else{
			tokenAttr = TokenAttr::DELIMITER;
			this->phrase_ = ScanPhrase::END;
		}
	}
	void Scanner::handleDoubleDelimiter(std::string& tokenName, TokenAttr& tokenAttr){
		tokenAttr = TokenAttr::DELIMITER;
		this->phrase_ = ScanPhrase::END;
	}
	Token Scanner::handleEnd(std::string& name, 
							const TokenAttr tokenAttr, 
							const size_t location){
		return Token(name, tokenAttr, this->fileName_, location);
	}

	Token Scanner::getNextToken(){
		this->phrase_ = ScanPhrase::BEGIN;
		std::string tokenName;
		TokenAttr tokenAttr = TokenAttr::UNKNOWN;

		skipBlank();//跳过前导空白
		while (citer_ != code_.cend() && *(citer_) != EOF){
			switch (this->phrase_){
			case ScanPhrase::BEGIN:
				handleBegin(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_SINGLEDELIMITER:
				handleSingleDelimiter(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_DOUBLEDELIMITER:
				handleDoubleDelimiter(tokenName, tokenAttr);
				break;
			case ScanPhrase::IN_INTEGER:
				handleInteger(tokenName, tokenAttr);
				break;
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
				auto tok = handleEnd(tokenName, tokenAttr, location_);
				return tok;
			}
			//++citer_;
		}
		return Token("", TokenAttr::UNKNOWN, "", -1);
	}

	std::vector<Token> Scanner::getTokens(){
		std::vector<Token> toks;
		Token tok;
		while ((tok = getNextToken()).getTokenAttr() != TokenAttr::UNKNOWN){
			toks.push_back(tok);
		}
		return toks;
	}
}