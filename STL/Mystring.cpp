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
		{
			if (nullptr == str)
				str = "";
			
			//ÉêÇë¿Õ¼ä
			_str = new char[strlen(str)+1]; //¡°\0¡±
			strcpy(_str, str);
		}

		//Éî¿½±´
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

		//Éî¿½±´ ¸Ä
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

		//Ç³¿½±´
		string(const string& s)
			:_str(s._str)
		{ }

		string &operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}
		

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

int main()
{
	my::string s("hello");
	my::string s2(s);

	return 0;
}