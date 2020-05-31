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
链接：https://www.nowcoder.com/questionTerminal/9173e83d1774462f81255a26feafd7c6?answerType=1&f=discussion
来源：牛客网

牛牛总是睡过头，所以他定了很多闹钟，只有在闹钟响的时候他才会醒过来并且决定起不起床。从他起床算起他需要X分钟到达教室，上课时间为当天的A时B分，请问他最晚可以什么时间起床

输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N<=100)。
接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0<=A<24)时Mi(0<=B<60)分。
接下来的一行包含一个整数，表示从起床算起他需要X(0<=X<=100)分钟到达教室。
接下来的一行包含两个整数，表示上课时间为A(0<=A<24)时B(0<=B<60)分。
数据保证至少有一个闹钟可以让牛牛及时到达教室。


输出描述:
输出两个整数表示牛牛最晚起床时间。
示例1
输入
3
5 0
6 0
7 0
59
6 59
输出
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