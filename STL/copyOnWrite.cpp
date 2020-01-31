#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

namespace my
{
	class string
	{
	public:
		string(char* str = "")
			:_pCount(new int(1))
		{
			if (nullptr == str)
				str = "";

			//申请空间
			_str = new char[strlen(str) + 1]; //“\0”
			strcpy(_str, str);
		}

		//浅拷贝
		string(const string& s)
			:_str(s._str)
			, _pCount(s._pCount)
		{
			++*_pCount;
		}

		string &operator=(const string& s)
		{
			if (this != &s)
			{
				//需要将当前对象的旧资源释放掉
				if (0 == --*_pCount)
				{
					delete[] _str;
					delete _pCount;
				}
				_str = s._str;
				_pCount = s._pCount;
				(*_pCount)++;
			}
			return *this;
		}


		~string()
		{
			if (_str && --*_pCount == 0)
			{
				delete[] _str;
				_str = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}

		char& operator[](size_t index)
		{
			if (GetRef() > 1)
			{
				string strtemp(_str);
				this->swap(strtemp);
			}
			return _str[index];

		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_pCount, s._pCount);
		}

	private:
		int GetRef()
		{
			return *_pCount;
		}
		char* _str;
		int* _pCount;
	};
}

int main()
{
	my::string s1("abcde");
	my::string s2(s1);
	my::string s3;
	s3 = s1;
	s1[0] = 'A';
	return 0;
}