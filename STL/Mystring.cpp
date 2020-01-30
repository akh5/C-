#include <stdio.h>
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
			
			//����ռ�
			_str = new char[strlen(str)+1]; //��\0��
			strcpy(_str, str);
		}

		//���
		/*string(const string& s)
			:_str(new char[strlen(s._str)])
		{
			strcpy(_str, s._str);

		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str)];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
			}
		}*/

		//��� ��
		/*string(const string& s)
			:_str(nullptr)
		{
			string strtemp(s._str);
			swap(_str, strtemp._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string strtemp(s);
				swap(_str, strtemp);
			}
		}

		string& operator=(const string& s)
		{
			swap(_str, s._str);
			return *this;
		}*/

		//ǳ����
		string(const string& s)
			:_str(s._str)
			,_pCount(s._pCount)
		{
			++_count;
		}

		string &operator=(const string& s)
		{
			if (this != &s)
			{
				//��Ҫ����ǰ����ľ���Դ�ͷŵ�
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
			if (_str && --*_pCount==0 )
			{
				delete[] _str;
				_str = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}

		char& operator[](size_t index)
		{
			return _str[index];
		}
	private:
		char* _str;
		int* _pCount;
	};

	//int string::_count = 0;
}


int main()
{
	my::string s("hello");
	my::string s2(s);

	return 0;
}