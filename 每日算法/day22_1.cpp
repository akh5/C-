#include<iostream>
#include<list>

using namespace std;

int main(){
	int month;
	while (cin >> month){
		int rabbit = 1;
		list<int> newrabbit;
		for (int i = 3; i <= month; i++){
			if (2 == newrabbit.size()){
				rabbit += newrabbit.front();
				newrabbit.pop_front();
			}
			newrabbit.push_back(rabbit);

		}
		while(!newrabbit.empty()){
			rabbit += newrabbit.front();
			newrabbit.pop_front();
		}
		cout << rabbit<< endl;

	}

	return 0;
}