#include <iostream>
#include <vector>

using namespace std;

bool Fibna(int test){
	int a = 1;
	int b = 1;
	int fib = 1;
	while (test != fib){
		fib = a + b;
		a = b;
		b = fib;
		if (fib > test){
			return false;
		}
	}
	return true;
	
}

int main(){

	int n;
	cin >> n;
	int flag = 0;
	int N_ = n;
	int _N = n;
	while (n--){
		if (Fibna(_N--)){
			cout << flag;
			return 0;
		}
		if (Fibna(N_++)){
			cout << flag;
			return 0;
		}
		flag++;
	}

	return 0;
}