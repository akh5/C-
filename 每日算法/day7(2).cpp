#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	vector<string> arr;
	string temp;
	for (auto e : str){
		if (e != ' '){
			temp.push_back(e);
		}
		else{
			temp.push_back(' ');
			arr.push_back(temp);
			temp.clear();
		}
	}
	temp.push_back(' ');//去空格
	arr.push_back(temp);
	arr[0].pop_back();

	for (vector<string>::iterator it = arr.end()-1; it >= arr.begin(); it--)//从后往前输出
	{
		cout << *it;
		if (it == arr.begin()){
			break;
		}
	}

	return 0;
}