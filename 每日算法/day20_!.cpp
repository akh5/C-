#include<iostream>
#include<math.h>

using namespace std;

bool perfect(int n){   //����ȫ���Ļ�
	int sum = 0;
	for (int i = 2; i < sqrt(n*1.0); i++){
		if (n%i == 0){     //�ҵ�Լ��
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