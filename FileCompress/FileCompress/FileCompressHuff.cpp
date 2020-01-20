#include "FileCompressHuff.h"
#include <assert.h>
//#include "HuffmanTree.hpp"
FileCompressHuff::FileCompressHuff()
{
	_fileInfo.resize(256);
	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;

	}
}

void FileCompressHuff::CompressFile(const std::string& path)
{
	FILE* fIn = fopen(path.c_str(), "r");
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}

	char* pReadBuff = new char[1024];
	int rdSize = 0;
	while (1)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;
		for (int i = 0; i < rdSize; i++)
		{
			_fileInfo[pReadBuff[i]]._count++;
		}
	}
	HuffManTree<CharInfo> t(_fileInfo,CharInfo(0));  //第二参数？

	GenerateHuffManCode(t.GetRoot());
	
	FILE* fOut = fopen("2.txt", "w");
	if (nullptr == fOut)
	{
		assert(false);
		return;
	}

	WriteHead(fOut, path);
	fseek(fIn, 0, SEEK_SET);
	char ch = 0;
	int bitcount = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (rdSize == 0)
			break;
		//根据字节编码对读取到的内容进行重写
		for (int i = 0; i < rdSize; i++)
		{
			std::string strCode = _fileInfo[pReadBuff[i]]._strCode;
			for (int j = 0; j < strCode.size(); j++)
			{
				ch <<= 1;
				if (strCode[i] == '1')
					ch |= 1;

				bitcount++;
				if (bitcount == 8)
				{
					fputc(ch, fOut);
					bitcount = 0;
					ch = 0; 
				}
			}
		}
	}

	//最后依次ch中可能不够8个bit
	if (bitcount < 8)
	{
		ch <<= (8 - bitcount);
		fputc(ch, fOut);

	}

	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuff::UNCompressFile(const std::string& path)
{
	FILE* fIn = fopen(path.c_str(), "r");
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}
	std::string strFilePostFix; //文件后缀
	ReadLine(fIn,strFilePostFix);

	std::string strCount;
	ReadLine(fIn, strCount);
	int lineCount = atoi(strCount.c_str());
	for (int i = 0; i < lineCount; i++)
	{
		std::string strchCount;
		ReadLine(fIn, strchCount);
		//如果读取到的时\n
		if (strchCount.empty())
		{
			strchCount += '\n';
			ReadLine(fIn, strchCount);
		}

		//跳过  字符和： 前两个字符
		_fileInfo[(unsigned char)strchCount[0]]._count = atoi(strCount.c_str() + 2);
	}
	HuffManTree<CharInfo> t;
	t.CreatHuffManTree(_fileInfo, CharInfo(0));

	FILE* fOut = fopen("3.txt", "w");
	assert(fOut);
	//解压缩
	unsigned char* pRreadBuff = new unsigned char[1024];
	char ch = 0;
	HuffManTreeNode<CharInfo>* pCur = t.GetRoot();
	size_t fileSize = pCur->_weight._count;
	size_t unCount = 0;

	while (true)
	{
		size_t rdSize = fread(pRreadBuff,1, 1024,fIn);
		if (0 == rdSize)
			break;

		for (size_t i = 0; i < rdSize; ++i)
		{
			//只需将一个字节中的8个比特位单独处理
			ch = pRreadBuff[i];
			for (int pos = 0; pos < 8; ++pos)
			{
				if (ch & 0x80)
					pCur = pCur->_pRight;
				else
					pCur = pCur->_pLeft;
				ch <<= 1;
				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
				{
					unCount++;
					fputc(pCur->_weight._ch, fOut);
					if (unCount == fileSize)
						break;
					
					pCur = t.GetRoot();
				}
			}
		}

	}
	delete[] pRreadBuff;
	fclose(fIn);
	fclose(fOut);

}

void FileCompressHuff::ReadLine(FILE* fIn, std::string& strInfo)
{
	assert(fIn);

	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if (ch != '\n')
			break;
		strInfo += ch;
	}
	
	
}

void FileCompressHuff::WriteHead(FILE* fOut, const std::string& fileName)
{
	assert(fOut);
	//后缀
	std::string strHead;
	strHead += GetFilePostFix(fileName);
	strHead += '\n';
	//fwrite(filePostFix.c_str(), 1, filePostFix.size(), fOut);
	//行数
	size_t lineCount = 0;
	std::string strChCount;
	char szValue[32] = { 0 };
	for (int i = 0; i < 256; i++)
	{
		CharInfo& charInfo = _fileInfo[i];
		if (_fileInfo[i]._count)
		{
			lineCount++;
			strChCount += _fileInfo[i]._ch;
			strChCount += ':';
			_itoa(charInfo._count, szValue, 10);
			strChCount += szValue;
			strChCount += '\n';
		}
	}
	_itoa(lineCount, szValue, 10);
	strHead += szValue;
	strHead += '\n';
	strHead += strChCount;
	strHead += '\n';

	fwrite(strHead.c_str(),1,strHead.size(),fOut);

	//写字符次数信息
}

std::string FileCompressHuff::GetFilePostFix(const std::string& fileName)
{
	
	return fileName.substr(fileName.rfind('.'));
}

void FileCompressHuff::GenerateHuffManCode(HuffManTreeNode<CharInfo>* pRoot)
{
	if (nullptr == pRoot)
		return;

	GenerateHuffManCode(pRoot->_pLeft);
	GenerateHuffManCode(pRoot->_pRight);

	if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)
	{
		std::string& strCode = _fileInfo[pRoot->_weight._ch]._strCode ;
		HuffManTreeNode<CharInfo>* pCur = pRoot;
		HuffManTreeNode<CharInfo>* pParent = pCur->_pParent;

		while (pParent)
		{
			if (pCur == pParent->_pLeft)
			{
				strCode += '0';
			}
			else
			{
				strCode += '1';
			}
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());

		//_fileInfo[pRoot->_weight._ch] = strCode;
	}
}