#include<iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	if (a < b){
		int temp = a;
		a = b;
		b = temp;
	}
	int tempa = a, tempb = b;
	int approm = tempb;
	while (tempb != 0){
		int y = tempa%tempb;
		tempa = tempb;
		tempb = y;
		approm = tempa;
	}
	cout << (a*b / approm);

	return 0;
}