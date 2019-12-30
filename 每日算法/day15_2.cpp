#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	int con = 0, large = 0;
	vector<int>bite;
	while (n){
		bite.push_back(n % 2);
		n >>= 1;
	}
	bite.push_back(0);
	for (int i = 0; i < bite.size(); i++){
		if (bite[i] == 1){
			con++;
		}
		else{
			if (large < con){
				large = con;
			}
			con = 0;
		}
	}
	cout << large;

	return 0;
}
