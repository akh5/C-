#include<iostream>

using namespace std;

int getLCA(int a, int b) {
	// write code here
	int pl , pr ;
	if (a % 2 == 0&&b%2==0){
		(a < b) ?( pl = a, pr = b) :( pl = b, pr = a);
	}
	else if (a % 2 == 0){
		pl = a;
		pr = b;
	}
	else{
		pl = b;
		pr = a;
	}
	while (pl!=pr){
		if (pr < pl){
			pl /= 2;
		}
		else{
			pr /= 2;
		}
	}
	return pl;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << getLCA(a, b);
	return 0;
}