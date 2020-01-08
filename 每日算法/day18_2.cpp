#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int>num(n);
	int bag = 0;
	int num1 = 0;
	for (int i = 0; i < n; i++){
		cin >> num[i];
		if (num[i] == 1){
			num1++;
		}
	}
	sort(num.begin(), num.end());
	bag += num.size() - num1;//袋中有1个1时候
	bag *= num1;
	int plus = 1;
	for (; plus <= 3; plus++){
		for (int i = 0; i <= num.size(); i++){

		}
	}
	

	return 0;
}