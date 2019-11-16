#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool is_restr(string& str){
	for (int i = 0, j = str.length() - 1; i <= j; i++, j--){
		if (str[i] != str[j]){
			return false;
		}
	}
	return true;
}

int main() {
	string str;
	string instr;
	string laststr;
	cin >> str;
	cin >> instr;
	int flag = 0;
	laststr = str;
	for (int i = 0; i < str.length()+1; i++){
		str.insert(i, instr);
		if (is_restr(str)){
			flag++;
		}
		str = laststr;
	}
	cout << flag;
	//cout<<is_restr(str);
	return 0;
}