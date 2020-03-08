#include "hash_table.hpp"
#include <string>
#include <assert.h>
using namespace std;


class LZ77
{
public:
	const USH MIN_LOOKAHEAD = MAX_MAT + MIN_MAT + 1;
	const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;

	LZ77()
		:_pWin(new UCH[WSIZE*2])
		, _ht(WSIZE)
	{
	}

	~LZ77()
	{
		delete[] _pWin;
		_pWin = nullptr;
	}

	void CompressFile(const string& strFilePath)
	{
		FILE* fin = fopen(strFilePath.c_str(), "rb");
		if (nullptr == fin)
		{
			cout << "打开文件失败" << endl;
			return;
		}
		fseek(fin, 0, SEEK_END);
		ULL fileSize = ftell(fin);
		if (fileSize <= MIN_MAT)
		{
			cout << "文件过小" << endl;
			return;
		}
		fseek(fin, 0, SEEK_SET);
		size_t lookAhead = fread(_pWin, 1, 2 * WSIZE, fin);
		USH start = 0;
		USH hashAddr = 0;  
		for (USH i = 0; i < MIN_MAT - 1; i++) //先传入前两个字符
		{
			_ht.HashFunc(hashAddr, _pWin[i]);
		}

		//压缩
		FILE* fout = fopen("2.lzp", "wb");
		assert(fout);
		//USH start = 0;

		USH matchHead = 0;
		UCH curMatchLength = 0;  //error
		USH curMatchDist = 0;

		UCH chflag = 0;
		UCH bitCount = 0;
		bool isLen = false;
		FILE* foutf = fopen("3.txt", "wb");
		assert(foutf);

		//lookahead 先行缓冲区中剩余的个数
		while (lookAhead)
		{
			_ht.Insert(matchHead, _pWin[start+2], start, hashAddr);
			
			curMatchLength = 0;
			curMatchDist = 0; 

			if (matchHead)
			{
				//找到最长匹配
				curMatchLength = LongestMatch(matchHead,curMatchDist ,start);
			}
			if (curMatchLength < MIN_MAT)
			{
				//未找到，写入原字符
				fputc(_pWin[start],fout);
				WriteFlag(foutf,chflag,bitCount,false);
				start++;
				lookAhead--;

			}
			else
			{
				//写入长度距离对
				UCH chLen = curMatchLength - 3;
				fputc(chLen , fout);
				fwrite(&curMatchDist, sizeof(curMatchDist), 1, fout);

				WriteFlag(foutf, chflag, bitCount, true);

				lookAhead -= curMatchLength;
				--curMatchLength;
				while (curMatchLength)
				{
					start++;
					_ht.Insert(matchHead, _pWin[start+2], start, hashAddr);
					curMatchLength--;
				}
				start++;
			}
			if (lookAhead <= MIN_LOOKAHEAD)
				FileWindow(fin, lookAhead,start);
		}
		if (bitCount > 0 && bitCount < 8)
		{
			chflag <<= (8 - bitCount);
			fputc(chflag, foutf);
		}
		fclose(fin);
		fclose(foutf);
		//合并文件
		FILE* finf = fopen("3.txt","rb");
		unsigned long flagsize = 0;
		UCH* pReadbuff = new UCH[1024];

		while (true)
		{
			size_t rdsize = fread(pReadbuff, 1, 1024, finf);
			if (rdsize == 0)
			{
				break;
			}
			fwrite(pReadbuff, 1, rdsize, fout);
			flagsize += rdsize;
		}
		fwrite(&flagsize, sizeof(flagsize), 1, fout);
		fwrite(&fileSize, sizeof(fileSize), 1, fout);
		fclose(finf);
		fclose(fout);
		delete[] pReadbuff;
	}

	void UNCompressfile(const string& strFilePath)
	{
		FILE* finD = fopen("2.lzp", "rb");
		if (nullptr == finD)
		{
			cout << "打开压缩文件失败" << endl;
			return;
		}
		FILE* finF = fopen("2.lzp", "rb");
		if (nullptr == finF)
		{
			cout << "打开压缩文件失败" << endl;
			return;
		}
		ULL filesize = 0;
		fseek(finF, 0 - sizeof(filesize), SEEK_END);
		fread(&filesize, sizeof(filesize), 1, finF);

		size_t flagsize = 0;
		fseek(finF, 0 - sizeof(filesize)-sizeof(flagsize), SEEK_END);
		fread(&flagsize, sizeof(flagsize), 1, finF);
		fseek(finF, 0 - sizeof(flagsize)-sizeof(filesize)-flagsize, SEEK_END);

		FILE* fout = fopen("out.txt", "wb");
		assert(fout);

		FILE* f = fopen("out.txt", "rb");
		assert(f);
		UCH bitCount = 0;
		UCH chflag = 0;
		ULL encodeCount = 0;
		while (encodeCount<filesize)  //!feof(finD)
		{
			if (0 == bitCount)
			{
				chflag = fgetc(finF);
				bitCount = 8;
			}
			if (chflag & 0x80)
			{
				//长度
				USH matchLen = fgetc(finD)+3;
				//距离
				USH matchDist = 0;
				fread(&matchDist, sizeof(matchDist), 1, finD);
				fflush(fout);
				encodeCount+=matchLen;
				UCH ch;
				fseek(f, 0 - matchDist, SEEK_END);
				while (matchLen)
				{
					ch = fgetc(f);
					fputc(ch, fout);
					matchLen--;
					fflush(fout);
				}
			}
			else
			{
				UCH ch = fgetc(finD);
				fputc(ch, fout);
				encodeCount++;		
			}
			chflag <<= 1;
			bitCount--;
			//fflush(fout);
		}
		fclose(finD);
		fclose(finF);
		fclose(fout);
		fclose(f);
	}
private:
	void FileWindow(FILE* fin,size_t& lookAhead,USH &start)
	{
		if (start >= WSIZE)
		{
			//右窗搬移左窗
			memcpy(_pWin, _pWin + WSIZE, WSIZE);
			memset(_pWin + WSIZE, 0, WSIZE);
			start -= WSIZE;	

			_ht.Update();

			//右窗补充数据
			if (!feof(fin))
			{
				lookAhead += fread(_pWin + WSIZE, 1, WSIZE, fin);

			}
		}
	}
	UCH LongestMatch(USH matchHead, USH& MatchDist,USH start)
	{
		UCH curMatchLen = 0;
		UCH maxMatchLen = 0;
		UCH maxMatchcount = 255;
		USH curMatchStart = 0;   //警告：从UCH强转为USH 导致压缩乱码

		USH limit = start > MAX_DIST ? start - MAX_DIST : 0;

		do
		{
			UCH* pstart = _pWin + start;
			UCH* pend = pstart + MAX_MAT;

			UCH* pMatchStart = _pWin + matchHead;
			
			curMatchLen = 0;
			while (pstart < pend&& *pstart ==*pMatchStart)
			{
				curMatchLen++;
				pstart++;
				pMatchStart++;
			}
			if (curMatchLen>maxMatchLen)
			{
				maxMatchLen = curMatchLen;
				curMatchStart = matchHead;
			}
		} while ((matchHead = _ht.GetNext(matchHead))>limit && maxMatchcount--);
		MatchDist = start - curMatchStart;
		return maxMatchLen;
	}
	void WriteFlag(FILE* fout, UCH& chflag, UCH& bitCount, bool isLen)
	{
		chflag <<= 1;
		if (isLen)
		{
			chflag |= 1;
		}
		bitCount++;
		if (bitCount == 8)
		{
			//将改标记写入
			fputc(chflag, fout);
			chflag = 0;
			bitCount = 0;
		}
		//chflag = 0;
	}
private:
	UCH *_pWin;
	LZHashTable _ht;
};