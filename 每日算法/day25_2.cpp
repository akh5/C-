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
���ӣ�https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a?source=relative
��Դ��ţ����

�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼��/usr/local/bin��������Ҫ�˴δ�����/usr������/usr/local���Լ���/usr/local/bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ�-p��ѡ�ֻҪһ�����mkdir -p /usr/local/bin�������Զ�������Ҫ���ϼ�Ŀ¼��
���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����

��������:
��������������ݡ�

ÿ�����ݵ�һ��Ϊһ��������n(1��n��1024)��

������n�У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ�����200���ַ���


�������:
��Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳������ġ�mkdir -p�����

ÿ������֮�����һ��������Ϊ�ָ���
*/

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> ls(n);
		vector<bool> out(n, true);
		for (int i = 0; i<n; i++)
		{
			cin >> ls[i];
		}
		sort(ls.begin(), ls.end());
		for (int i = 0; i<n - 1; i++)
		{
			if (ls[i] == ls[i + 1])
				out[i] = false;
			else if (ls[i].size() < ls[i + 1].size() && ls[i] == ls[i + 1].substr(0, ls[i].size()) && ls[i + 1][ls[i].size()] == '/')
				out[i] = false;
		}
		for (int i = 0; i < n; i++)
		{
			if (out[i])
				cout << "mkdir -p " << ls[i] << endl;
		}
		cout << endl;
	}
	return 0;
}