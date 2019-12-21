#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool cmp(string a,string b){
	for (int i = 0; i < a.length() || i < b.length(); i++){
		if (b[i]<a[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	vector<string> list;
	string str;
	for (int i = 0; i < n; i++){
		cin >> str;
		list.push_back(str);
	}
	int litter=0, len=0;
	for (int i = 1; i < list.size(); i++){
		if (cmp(list[i - 1], list[i])){
			litter++;
		}
		if (list[i].length()>list[i - 1].length()){
			len++;
		}
	}
	if (litter == list.size() && len == list.size()){
		cout << "both";
	}
	else if (litter == list.size()){
		cout << "litter";
	}
	else if (len == list.size()){
		cout << "lenth";
	}
	else{
		cout << "null";
	}

	return 0;
}