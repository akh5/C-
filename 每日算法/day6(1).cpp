#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	string sub;
	getline(cin, str);
	getline(cin, sub);
	for (int i = 0; i < sub.length(); i++){
		for (int j = 0; j <str.length(); j++){
			if (sub[i] == str[j]){
				str.erase(j, 1);
			}
		}
	}
	cout << str << endl;
	return 0;

}