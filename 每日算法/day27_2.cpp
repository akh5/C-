#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
/*
链接：https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836
来源：牛客网


说明：

1、构成单词的字符只有26个大写或小写英文字母；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；


输入描述:
输入一行以空格来分隔的句子



输出描述:
输出句子的逆序

示例1
输入
I am a student
输出
student a am I

*/

using namespace std;

int main()
{
	string str;
	while (getline(cin,str))
	{
		reverse(str.begin(), str.end());
		str.push_back(' ');
		auto bgin = str.begin();
		for (auto it = str.begin(); it != str.end(); it++)
		{
			if ((*it >= 'a'&&*it <= 'z') || (*it >= 'A'&&*it <= 'Z'))
			{
				continue;
			}
			else
			{
				*it = ' ';
			}
		}
		for (auto it = str.begin(); it != str.end(); it++)
		{
			if ((*it >= 'a'&&*it<='z') || (*it>='A'&&*it <= 'Z')||*it==' ')
			{
				if (*it == ' ')
				{
					reverse(bgin, it);
					bgin = it + 1;
				}
			}
			else
			{
				*it = ' '; 
				it++;
			}
		}
		bool start = true;
		str.pop_back();
		for (auto it = str.begin(); it != str.end();)
		{
			
			if (start&&*it==' ')
			{
				str.erase(it);
			}
			else if (*it == ' ')
			{
				it++;
				if (it == str.end())
				{
					break;
				}
				if (*it == ' ')
				{
					str.erase(' ');
					it++;
				}
			}
			else{
				start = false;
				it++;
			}
		}
		
		cout << str << endl;
	}

	return 0;
}