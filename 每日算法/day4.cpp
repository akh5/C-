#include<iostream>
#include <algorithm>
using namespace std;


int main(){

	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	int temp;
	arr[0] + arr[1] > arr[0] * arr[1] ?
		temp = arr[0] + arr[1] :
		temp = arr[0] * arr[1];
	cout << max(arr[2] + temp, arr[2] * temp);

	return 0;
}