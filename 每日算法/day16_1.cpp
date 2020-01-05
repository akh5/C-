#include<iostream>
#include<math.h>
using namespace std;
bool isprem(int n){
	for (int i = 2; i <= sqrt(n*1.0); i++){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;


	for (int i = n / 2; i > 1; i--){
		if (isprem(i) && isprem(n - i)){
			cout << i << endl;
			cout << n - i << endl;
			return 0;
		}
	}
	return 0;
}