#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	vector<string> list;
	string str;
	string temp;
	getline(cin, str);
	int i = 0;
	int flag = 0;
	for (; i < str.length()+1; i++){
		if (str[i] == ' '||i==str.length()){
			list.push_back(temp);
			temp.clear();
			flag++;
		}else
		temp.push_back(str[i]);
	}
	cout << flag << endl;
	for (vector<string>::iterator it = list.begin(); it < list.end(); it++){
		cout << *it << endl;
	}

	return 0;
}