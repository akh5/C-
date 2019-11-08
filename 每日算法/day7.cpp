#include <iostream>
#include <vector>
using namespace std;
#if 0
int main() {
	int a;
	cin >> a;
	vector<int> arr(a);
	for (int i = 0; i < a; i++){
		cin >> arr[i];
	}
	int flag = 1;
	vector<int> add;
	vector<int> dev;
	int n = 0;
	for (vector<int>::iterator it = arr.begin() + 1; it < arr.end()-1; it+=2){
		if (*(it - 1) < *it){
			n++;
			if (*(it) > *(it + 1)){
				add.push_back(n);
				n = 0;
			}
		}
		if (*(it - 1) > *it ){
			n++;
			if (*(it) < *(it + 1)){
				dev.push_back(n);
				n = 0;
			}
		}
		
	}
	flag += add.size() + dev.size();
	cout << flag;

	return 0;
}

int main()
{
	int a;
	int flag = 1;
	cin >> a;
	vector<int> arr(a+1);
	for (int i = 0; i < a; i++)
		cin >> arr[i];

	for (int i = 1; i < a-1; i ++)
	{
		if (arr[i - 1]<arr[i] && arr[i]>arr[i + 1])//找最大点
		{
			flag++;
		}
		if (arr[i - 1]>arr[i] && arr[i + 1]>arr[i])//找最小点
		{
			flag++;
		}
	}

	cout << flag << endl;
	return 0;
}
#endif

int main()
{
	int a;
	int flag = 1;
	cin >> a;
	vector<int> arr(a);
	for (int i = 0; i < a; i++)
		cin >> arr[i];

	for (int i = 1; i < a - 1; i++)
	{
		if (arr[i - 1]<arr[i] && arr[i]>arr[i + 1] || arr[i - 1]>arr[i] && arr[i + 1]>arr[i])//找最大点或最小点
		{
			flag++;
			if (i < a - 3)
				i++;
		}
	}

	cout << flag << endl;
	return 0;
}