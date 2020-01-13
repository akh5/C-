#include<iostream>

using namespace std;

int main(){
	int n;

	while (cin >> n){
		int flag = 0;
		while (n){
			if (n % 2 == 1){
				flag++;
				
			}
			n /= 2;
		}
		cout << flag << endl;
	}



	return 0;
}