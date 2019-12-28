#include<iostream>

using namespace std;

int C(int a, int b){
	long long up = 1;
	long long low = 1;
	for (int i = a; i >= 1; i--){
		up *= i;
	}
	for (int i = b; i >= 1; i--){
		low *= i;
	}
	for (int i = a - b; i >= 1; i--){
		low *= i;
	}
	return (up / low)%1000000007;
}

int main(){
	int m, n;
	cin >> m >> n;

	cout << C(m+n,m);
	return 0;
}