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
���ӣ�https://www.nowcoder.com/questionTerminal/01e7bedf5dd2421aa6f879fd8055e51d?toCommentId=5442492
��Դ��ţ����

���������ļ��������ţţ�ڼ��ر����ģ�������������һ��С��Ϸ����Ϸ����Ϊ�����ַ���������Ϊż��λ�����ֽ��з�ת������ת��Ľ�����������
ʾ��1
����
"1234"
���
"1432"
˵��
��2��4λΪż�������Խ��䷭ת�󣬵õ� 1432
****/

class Solution {
public:
	/**
	*
	* @param number string�ַ���
	* @return string�ַ���
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