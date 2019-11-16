#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	//vector<vector<int>> sarr;
	vector<int>sarr;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 0; i < n-1; i++){
		int j = i;
		if (arr[i ] >= arr[i+1]){
			sum += arr[i];
			while (i<n-1&&arr[i] >= arr[i + 1]){
				sum += arr[i + 1];
				i++;
			}
			sarr.push_back(sum);
			sum = 0;
			i = j;
			}

		if (i<n-1&&arr[i] <= arr[i + 1]){
			sum += arr[i];
			while (arr[i] <= arr[i + 1]){
				sum += arr[i + 1];
				i++;
			}
			sarr.push_back(sum);
			sum = 0;
			i = j;
			}
		}

	auto maxPosition = max_element(sarr.begin(), sarr.end());
	cout << *maxPosition;



	return 0;
}