#include<iostream>
#include<string>

using namespace std;

int main(){
	string ins;
	string add;
	cin >> ins>>add;
	

	if (ins.length() < add.length()){
		string temp;
		temp = ins;
		ins = add;
		add = temp;
	}

	int carry = 0;
	int i = ins.length() - 1;
	int a = add.length() - 1;
	for (; i >=0; i--,a--){
		if (a >=0){
			ins[i] = (ins[i] - '0') + (add[a] - '0');
			ins[i] += carry;
			if (ins[i] >= 10){
				ins[i] -= 10;
				carry = 1;
			}
			else{
				carry = 0;
			}
		}
		else{
			ins[i] = (ins[i] - '0') + carry;
			if (ins[i] >= 10){
				ins[i] -= 10;
				carry = 1;
			}
			else{
				carry = 0;
			}
		
		}
		ins[i] += 48;
		if (i == 0 && carry == 1){
			ins.insert(0,"1");
			carry = 0;
		}if (i == 0  && carry == 0){
			break;
		}
		
		
		
	}
	
	
	cout << ins << endl;

	return 0;
}

/* 在线OJ 循环输入版本

#include<iostream>
#include<string>

using namespace std;

int main(){
string ins;
string add;
while(cin >> ins>>add){


if (ins.length() < add.length()){
string temp;
temp = ins;
ins = add;
add = temp;
}

int carry = 0;
int i = ins.length() - 1;
int a = add.length() - 1;
for (; i >=0; i--,a--){
if (a >=0){
ins[i] = (ins[i] - '0') + (add[a] - '0');
ins[i] += carry;
if (ins[i] >= 10){
ins[i] -= 10;
carry = 1;
}
else{
carry = 0;
}
}
else{
ins[i] = (ins[i] - '0') + carry;
if (ins[i] >= 10){
ins[i] -= 10;
carry = 1;
}
else{
carry = 0;
}

}
ins[i] += 48;
if (i == 0 && carry == 1){
ins.insert(0,"1");
carry = 0;
}if (i == 0  && carry == 0){
break;
}



}


cout << ins << endl;
}

return 0;
}

*/