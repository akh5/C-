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
链接：https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e?orderByHotValue=1&done=0&pos=10&onlyReference=false
来源：牛客网

Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。

现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接。

输入描述 :
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000），表示请求的数量。

紧接着n行，每行包含一个请求编号id（A、B、C……、Z）和操作（connect或disconnect）。


输出描述 :
对应每一组数据，输出连接池最多需要创建多少个连接。
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