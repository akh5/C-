#include<iostream>
#include<math.h>

using namespace std;

bool perfect(int n){   //是完全数的话
	int sum = 0;
	for (int i = 2; i < sqrt(n*1.0); i++){
		if (n%i == 0){     //找到约数
			sum += i + n / i;
		}
	}
	sum++;
	if (sum == n){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 2; i <= n; i++){
		if (perfect(i))
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}