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
���ӣ�https://www.nowcoder.com/questionTerminal/16fa68271ee5448cafd504bb4a64b482
��Դ��ţ����

nowcoderҪ�����ѽ���һЩ���е���Ϣ���������ĵ绰����ȡ������Ҫ����Щ������Ϣ���л����������������м����һЩ����ķ��ţ�������������һ�����롣
���������æ����һ����򣬽�����nowcoder�Ƕ����յ�����Ϣ����ȡ���м����õ���Ϣ��

��������:
�����ж��С�

ÿһ����һ�ξ������ܵ���Ϣ�����п��ܰ����ո񣩣�����ԭʼ��Ϣ���Ȳ�ȷ����


�������:
���ÿ����Ϣ��������Ϣ��
ʾ��1
����
$Ts!47&*s456  a23* +B9k
���
47456239

*/

using namespace std;

int main()
{
	string str;
	while (getline(cin,str))
	{
		string out;
		for (int i = 0; i<str.size(); i++)
		{
			if (str[i] - '0' >= 0 && str[i] - '0'<10)
			{
				out.push_back(str[i]);
			}
		}
		cout << out << endl;
	}
	return 0;
}