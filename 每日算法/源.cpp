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
���ӣ�https://www.nowcoder.com/questionTerminal/9173e83d1774462f81255a26feafd7c6?answerType=1&f=discussion
��Դ��ţ����

ţţ����˯��ͷ�����������˺ܶ����ӣ�ֻ�����������ʱ�����Ż��ѹ������Ҿ������𴲡���������������ҪX���ӵ�����ң��Ͽ�ʱ��Ϊ�����AʱB�֣��������������ʲôʱ����

��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а���һ������������ʾ���ӵ�����N(N<=100)��
��������N��ÿ�а���������������ʾ������������ʱ��ΪHi(0<=A<24)ʱMi(0<=B<60)�֡�
��������һ�а���һ����������ʾ������������ҪX(0<=X<=100)���ӵ�����ҡ�
��������һ�а���������������ʾ�Ͽ�ʱ��ΪA(0<=A<24)ʱB(0<=B<60)�֡�
���ݱ�֤������һ�����ӿ�����ţţ��ʱ������ҡ�


�������:
�������������ʾţţ������ʱ�䡣
ʾ��1
����
3
5 0
6 0
7 0
59
6 59
���
6 0

*/

class clock
{
public:
	clock(int a, int b)
		:hour(a)
		, min(b)
	{}
	clock()
	{
	}
	void get(int a, int b)
	{
		hour = a;
		min = b;
	}
	void operator-(int x)
	{
		while(min < x)
		{
			min += 60;
			hour--;
		}
		min -= x;
	}
	bool operator<=(clock c)
	{
		if (hour < c.hour)
		{
			return true;
		}
		else if (hour == c.hour)
		{
			if (min <= c.min)
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}

public:
	int hour;
	int min;
};

int main()
{
	int n;
	cin >> n;
	vector<clock*> cs(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cs[i] = new clock(a, b);
	}
	int x;
	cin >> x;
	int ca, cb;
	cin >> ca >> cb;
	clock *ctime = new clock(ca, cb);
	*ctime - x;
	int i = 0;
	for (; i < n; i++)
	{
		if (*ctime <= *cs[i])
			break;
	}
	cout << (*cs[i]).hour << " " << (*cs[i]).min << endl;

	return 0;
}