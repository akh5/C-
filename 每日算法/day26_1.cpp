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
链接：https://www.nowcoder.com/questionTerminal/16fa68271ee5448cafd504bb4a64b482
来源：牛客网

nowcoder要和朋友交流一些敏感的信息，例如他的电话号码等。因此他要对这些敏感信息进行混淆，比如在数字中间掺入一些额外的符号，让它看起来像一堆乱码。
现在请你帮忙开发一款程序，解析从nowcoder那儿接收到的信息，读取出中间有用的信息。

输入描述:
输入有多行。

每一行有一段经过加密的信息（其中可能包含空格），并且原始信息长度不确定。


输出描述:
输出每段信息中数字信息。
示例1
输入
$Ts!47&*s456  a23* +B9k
输出
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