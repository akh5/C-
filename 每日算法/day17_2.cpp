#include<iostream>

using namespace std;

int largeAppro(int n){
	int app = 2;
	while (n%app != 0){
		app++;
	}
	return n/app;
}

int main(){
	int n, m;
	cin >> n >> m;
	int step = 0;
	int stone = n;
	while (stone < m){
		stone += largeAppro(stone);
		step++;
		
	}
	cout << step << endl;

	return 0;
}