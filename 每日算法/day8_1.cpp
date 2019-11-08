#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
	vector<string> num;
	string str;
	string temp;
	cin >> str;
	int sum = 0;
	for (string::iterator it = str.begin(); it < str.end(); it++){
		if (*it >= 48 && *it <= 57){
			temp.push_back(*it);
			sum++;
		}
		else{
			if (sum != 0){
				num.push_back(temp);
				temp.clear();
				sum = 0;
			}
		}
		if (it == str.end() - 1 && sum != 0){
			num.push_back(temp);
		}
	}
	int large = 0;
	int pos = 0;
	for (int i = 0; i < num.size(); i++){
		if (num[i].length() >= large){
			large = num[i].length();
			pos = i;
		}
	}
	cout << num[pos];

	return 0;
}