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
���ӣ�https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e?orderByHotValue=1&done=0&pos=10&onlyReference=false
��Դ��ţ����

Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲΪ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��ʣ����õ�����ʱ��ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�

�����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�

�������� :
��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000������ʾ�����������

������n�У�ÿ�а���һ��������id��A��B��C������Z���Ͳ�����connect��disconnect����


������� :
��Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ����ӡ�
*/

void check(map<char, string> con, int& now)
{
	now = 0;
	for (auto it = con.begin(); it != con.end(); it++)
	{
		if (it->second == "connect")
			now++;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		map<char, string> con;
		int maxcon = 0, now = 0;
		char c;
		string str;
		for (int i = 0; i<n; i++)
		{
			cin >> c >> str;
			con[c] = str;
			check(con, now);
			maxcon = max(maxcon, now);
		}
		cout << maxcon << endl;
	}

	return 0;
}