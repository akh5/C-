#include <iostream>
#include <string>

using namespace std;

int main(){

	int m, n;
	char c;
	string str;
	cin >> m >> n;
	while (m){
		if (m%n <= 9){
			c = m%n + 48;
		}
		else{
			c = m%n - 9 + 64;
		}
		
		str.push_back(c);
		m /= n;
	}
	for (int i = str.length()-1; i >= 0; i--){
		cout << str[i];
	}
	return 0;
}