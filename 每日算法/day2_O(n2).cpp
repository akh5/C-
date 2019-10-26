#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<int> vec) {
	int max = -1;
	for (auto v : vec) {
		if (max < v) max = v;
	}
	return max;
}

int main(){
	int n, k;
	vector<int> point;
	vector<int>awake;
	vector<int>save_awake;
	vector<int>highpoint;
	cin >> n >> k;
	point.resize(n);
	awake.resize(n);

	for (int i = 0; i < n; i++){
		cin >> point[i];
	}
	for (int i = 0; i < n; i++){
		cin >> awake[i];
	}
	for (int x = 0; x < n; x++){
		int plus = 0;
		save_awake = awake;
		if (save_awake[x] == 0){
			for (int y = 0; y < k; y++){
				if ((x + y) >= n)
					break;
				save_awake[x + y] = 1;
			}
			for (int i = 0; i < n; i++){
				if (save_awake[i] == 1)
					plus += point[i];
			}
			highpoint.push_back(plus);
		}
	}
	cout << findMax(highpoint) << endl;


	return 0;
}