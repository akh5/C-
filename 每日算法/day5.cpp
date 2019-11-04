#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<long> arr(n);
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	int left, right;
	long suml = 0;
	long sumr = 0;
	left = 0;
	right = n - 1;
	vector<long> sumall;
	//sumall.push_back(0);
	while (left < right){
		suml += arr[left];
		sumr += arr[right];
		if (suml == sumr){
			sumall.push_back(suml);
			left++;
			right--;
		}
		else if (suml<sumr){
			sumr -= arr[right];
			left++;
		}
		else{
			suml -= arr[left];
			right--;
		}
	}
	if (sumall.empty()){
		cout << 0;
	}
	else{
		auto maxPosition = max_element(sumall.begin(), sumall.end());
		cout << *maxPosition;
	}


	return 0;
}