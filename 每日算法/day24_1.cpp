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

bool iscon(int n)
{
	for (int i = 2; i <= sqrt((double(n))); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n = 100;
	for (int i = 2; i < n; i++)
	{
		if (iscon(i))
		{
			/*char str[5];
			itoa(i, str,10);*/
			string str;
			str = to_string(i);
			if (str[strlen(str.c_str()) - 1] == '1')
				cout << i << " ";
		}
	}	
	cout << endl;
	return 0;
}