#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

bool is_true(string& str){
	for (int i = 0; i < str.length(); i++){
		if (str[i] >41 && str[i] < 58){
			continue;
		}
		else
			return false;
	}
	return true;

}

int main(){
	string str;
	vector<char>number;
	vector<string>symbal;
	cin >> str;
	if (!is_true(str)){
		cout<<0;
		return 0;
	}
	for (int i = 0; i < str.length(); i++){
		if (str[i]>47 && str[i] < 58){
			number.push_back(str[i]);
		}
	}
	int sum = 0;
	int flag = 0;
	for (vector<char>::iterator it = number.end()-1; it >= number.begin(); it--){
		sum += (*it - 48)*pow(10,flag);
		flag++;
		if (it == number.begin()){
			break;
		}
	}
	cout<<sum;
	return 0;
}