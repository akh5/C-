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
���ӣ�https://www.nowcoder.com/questionTerminal/81544a4989df4109b33c2d65037c5836
��Դ��ţ����


˵����

1�����ɵ��ʵ��ַ�ֻ��26����д��СдӢ����ĸ��

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��


��������:
����һ���Կո����ָ��ľ���



�������:
������ӵ�����

ʾ��1
����
I am a student
���
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