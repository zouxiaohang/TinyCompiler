#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <cassert>
#include <vector>
#include <string>

#include "../Token/Token.h"

namespace TinyCompiler{

	class Scanner{
	private:
		enum class ScanPhrase{
			BEGIN,			
			IN_KEYWORD,		
			IN_STRING,		
			IN_INTEGER,		
			IN_REAL,		
			IN_SINGLEDELIMITER,	
			IN_DOUBLEDELIMITER, 
			IN_VARIALBE,	
			END				
		};
	private:
		ScanPhrase phrase_;
		std::string fileName_;
		std::string code_;
		//record the position where we now scan
		std::string::const_iterator citer_;
		//record the number of line where the token locates 
		size_t location_;
	private:
		bool openFile();
		void clear();
		void skipBlank();
		bool isDoubleDelimter(const char ch);

		void handleBegin(std::string& tokenName, TokenAttr& tokenAttr);
		void handleKeyWord(std::string& tokenName, TokenAttr& tokenAttr);
		void handleSingleDelimiter(std::string& tokenName, TokenAttr& tokenAttr);
		void handleDoubleDelimiter(std::string& tokenName, TokenAttr& tokenAttr);
		void handleInteger(std::string& tokenName, TokenAttr& tokenAttr);
		void handleReal(std::string& tokenName, TokenAttr& tokenAttr);
		void handleString(std::string& tokenName, TokenAttr& tokenAttr);
		void handleVariable(std::string& tokenName, TokenAttr& tokenAttr);
		Token handleEnd(std::string& name,
						const TokenAttr tokenAttr,
						const size_t location);
	protected:
		void setPhrase(const ScanPhrase phrase);
		ScanPhrase getPhrase() const;
		void setFileName(const std::string& fileName);
		std::string getFileName() const;
	public:
		explicit Scanner(const std::string& fileName) 
			:fileName_(fileName), phrase_(ScanPhrase::BEGIN), location_(1){
			auto ret = openFile();
			assert(ret);
		}

		//return all the tokens once
		std::vector<Token> getTokens();
		//return a token once a time
		Token getNextToken();
	};
}

#endif