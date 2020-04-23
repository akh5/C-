#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;

/****
链接：https://www.nowcoder.com/questionTerminal/01e7bedf5dd2421aa6f879fd8055e51d?toCommentId=5442492
来源：牛客网

在这个特殊的假期里，由于牛牛在家特别无聊，于是他发明了一个小游戏，游戏规则为：将字符串数字中为偶数位的数字进行翻转，将翻转后的结果进行输出。
示例1
输入
"1234"
输出
"1432"
说明
第2、4位为偶数，所以将其翻转后，得到 1432
****/

class Solution {
public:
	/**
	*
	* @param number string字符串
	* @return string字符串
	*/
	bool isodd(int n)
	{
		if (n % 2 == 0)
			return true;
		else
			return false;
	}

	string change(string number) {
		// write code here
		int i = 0;
		int j = number.size() - 1;
		bool flag = true;
		while (i < j)
		{
			if (isodd(number[i] - '0') && isodd(number[j] - '0'))
			{
				swap(number[i], number[j]);
				i++;
				j--;
			}
			else if (isodd(number[i] - '0'))
			{
				j--;
			}
			else if (isodd(number[j] - '0'))
			{
				i++;
			}
			else
			{
				i++;
				j--;
			}
		}
		cout << number << endl;
		return number;
	}
};


int main()
{
	string str = "123456";
	Solution s;
	s.change(str);
	return 0;
}