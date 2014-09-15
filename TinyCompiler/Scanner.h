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
		//记录当前解析到的源码的位置
		std::string::const_iterator citer;
	private:
		//打开文件，将文件的全部源码缓存至code_中
		bool openFile();
		//清空Scanner的内部状态
		//每次处理完一个文件的全部词素后调用
		void clear();
		//跳过每一行的前导空白
		void skipBlank(std::string::const_iterator& cit, size_t& location);

		//处理开始的情况
		void handleBegin(std::string& tokenName);
		//处理关键字
		void handleKeyWord(std::string& tokenName);
		//处理分隔符
		void handleDelimiter(std::string& tokenName);
		//处理整数
		void handleInteger(std::string& tokenName);
		//处理浮点数
		void handleReal(std::string& tokenName);
		//处理字符串
		void handleString(std::string& tokenName);
		//处理变量
		void handleVariable(std::string& tokenName);
		//处理结束的情况
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
			:fileName_(fileName), phrase_(ScanPhrase::BEGIN){}

		//一次性将全部的词素分出来
		std::vector<Token> getTokens();
		//将词素一个一个的分出来
		Token getNextToken();
	};
}

#endif