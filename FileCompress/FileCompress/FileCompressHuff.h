#pragma once
#include <string>
#include <vector>
#include "HuffmanTree.hpp"

struct CharInfo
{
	unsigned char _ch;
	size_t _count;
	std::string _strCode;

	CharInfo(size_t count = 0)
		:_count(count)
	{}
	CharInfo operator+(const CharInfo& c)
	{
		return CharInfo(_count + c._count);
	}
	bool operator>(const CharInfo& c)const
	{
		return _count > c._count;
	}
	bool operator==(const CharInfo& c)const
	{
		return _count == c._count;
		/*_ch == c._ch &&
			_strCode == c._strCode;*/
	}

};

class FileCompressHuff
{
public:
	FileCompressHuff();
	void CompressFile(const std::string& path);
	void UNCompressFile(const std::string& path);
	

private:
	void GenerateHuffManCode(HuffManTreeNode<CharInfo>* pRoot);
	void WriteHead(FILE* fOut,const std::string& filePostFix);
	std::string GetFilePostFix(const std::string& filename);
	void ReadLine(FILE* fIn, std::string& strInfo);

private:
	std::vector<CharInfo> _fileInfo;
};