#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> num(n * 3);
	vector<int> savenum(n * 3);
	vector<int> all_max(n * 3);
	for (int i = 0; i < n * 3; i++){
		cin >> num[i];
	}
	for (int i = 0; i < n * 3 / 2; i++){
		int temp = num[0];
		vector<int>::iterator it = num.begin();
		num.erase(it);
		num.push_back(temp);
		savenum = num;
		int sum = 0;
		for (vector<int>::iterator j = savenum.begin(); j < savenum.end() - 2; j += 3){
			sort(j, j + 3);
			sum += *(j + 1);
		}
		all_max.push_back(sum);
	}
	/*for (auto a : all_max){
	cout << a << " ";
	}
	cout << endl;*/
	auto maxPosition = max_element(all_max.begin(), all_max.end());
	cout << *maxPosition << endl;
	return 0;
}