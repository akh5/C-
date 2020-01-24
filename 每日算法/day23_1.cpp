#include<iostream>
#include<vector>

using namespace std;

int change(int bot){
	int count = 0;
	int empty = 0;
	if (bot < 3){
		return 0;
	}
	for (int i = bot; i >=0; i--,empty++){
		if (empty == 3){
			i++;
			count++;
			empty = 0;
		}
	}
	if (empty == 3){
		count++;
	}
	return count;
}

int main(){
	int n;
	while (cin >> n){
		cout << change(n) << endl;
	}
	return 0;
}