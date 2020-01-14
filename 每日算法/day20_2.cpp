#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;



int main(){
	string str;

	while (getline(cin, str)){
		string pocker1;
		string pocker2;
		string pf1;
		string pf2;
		int flag = 0;
		int n = 0;
		int p1 = 0, p2 = 0;
		for (auto i : str){
			n++;
			if (i == '-'){
				flag = 1;
				n = 0;
				continue;
			}
			if (flag == 0){
				pocker1.push_back(i);
				if (i == ' '){
					p1++;
				}
				if (p1 == 0){
					pf1.push_back(i);
				}

			}
			else{
				pocker2.push_back(i);
				if (i == ' '){
					p2++;
				}
				if (p2 == 0){
					pf2.push_back(i);
				}

			}
		}
		string order = "345678910JQKjokerJOKER";
		if (pocker1 == "joker JOKER" || pocker2 == "joker JOKER"){
			cout << "joker JOKER" << endl;
		}
		else{
			if (p1 == p2){
				if (order.find(pf1) > order.find(pf2)){
					cout << pocker1 << endl;
				}
				else{
					cout << pocker2 << endl;
				}
			}
			else{
				if (p1 == 3){
					cout << pocker1 << endl;
				}
				else if (p2 == 3){
					cout << pocker2 << endl;
				}
				else{
					cout << "ERROR" << endl;
				}
			}


		}
	}

	return 0;
}
