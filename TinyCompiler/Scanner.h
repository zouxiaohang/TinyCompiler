#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <vector>
#include <string>

#include "Token.h"

namespace TinyCompile{

	class Scanner{
	private:
		enum class ScanPhrase{
			BEGIN,			//开始
			IN_KEYWORD,		//处理关键字
			IN_STRING,		//处理字符串
			IN_INTEGER,		//处理整数
			IN_REAL,		//处理浮点数
			IN_DELIMITER,	//处理分隔符
			IN_VARIALBE,	//处理变量
			END				//结束
		};
	private:
		//分词的阶段
		ScanPhrase phrase_;
		//需要分词的源码文件
		std::string fileName_;
		//缓存源码
		std::string code_;
		//std::vector<Token> tokens_;
	private:
		//打开文件，将文件的全部源码缓存至code_中
		bool openFile();
	protected:
		void setPhrase(const ScanPhrase phrase);
		ScanPhrase getPhrase() const;
		void setFileName(const std::string& fileName);
		std::string getFileName() const;
	public:
		explicit Scanner(const std::string& fileName) 
			:fileName_(fileName), phrase_(ScanPhrase::BEGIN){}

		//一次性将全部的词素分出来
		std::vector<Token> getTokens();
		//将词素一个一个的分出来
		Token getNextToken();
	};
}

#endif