#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

vector<int> bite(int n){
	vector<int> b;
	while (n >= 1){
		b.push_back(n % 2);
		n >>= 1;
	}
	return b;
}

int main(){
	int n, m, j, i;
	cin >> n >> m >> j >> i;
	vector<int>b1 = bite(n);
	vector<int>b2 = bite(m);
	int l = 0;
	for (int s = j; s <=i ; s++){
		b1[s] = b2[l++];
	}
	int sum=0;
	int quater = 0;
	for (int y = 0; y <b1.size(); y++){
		sum += b1[y] * pow(2, quater++);
	}
	cout << sum;

	return 0;
}