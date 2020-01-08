#include<iostream>
#include<vector>

using namespace std;

bool leap(int y){
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int y, m, d;
	while (cin >> y >> m >> d){
		int sum = 0;
		vector<int> month = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (leap(y)){
			month[2] = 29;
		}
		if (m > 13 || m < 1 || d > month[m] || d < 1){
			cout << -1;
		}
		for (int i = 1; i < m; i++){
			sum += month[i];
		}
		sum += d;
		cout << sum << endl;
	}
	return 0;
}