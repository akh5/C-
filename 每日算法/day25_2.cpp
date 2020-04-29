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
链接：https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a?source=relative
来源：牛客网

工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“/usr/local/bin”，就需要此次创建“/usr”、“/usr/local”以及“/usr/local/bin”。好在，Linux下mkdir提供了强大的“-p”选项，只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。

输入描述:
输入包含多组数据。

每组数据第一行为一个正整数n(1≤n≤1024)。

紧接着n行，每行包含一个待创建的目录名，目录名仅由数字和字母组成，长度不超过200个字符。


输出描述:
对应每一组数据，输出相应的、按照字典顺序排序的“mkdir -p”命令。

每组数据之后输出一个空行作为分隔。
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