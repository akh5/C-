#include <iostream>
#include<string>
using namespace std;

int main(){
	size_t n, m;
	long long k;
	cin >> n >> m >> k;
	string a(n, 'a');
	string anext(n - 1, 'a');
	string z(m, 'z');
	string znext(m - 1, 'z');
	string nexta = anext + z;
	string nextz = a + znext;
	string comprise;
	int count = 0;
	//a开头第一个
	if (count == k){
		comprise = 'a' + nexta;
		cout << comprise << endl;
		return 0;
	}
	count++;
	//a开头
	int lastpos = nexta.size() - 1;
	for (int i = n - 2; i >= 0; i--){
		int j = i;
		for (; j < lastpos; j++){
			char temp;
			temp = nexta[j];
			nexta[j] = nexta[j + 1];
			nexta[j + 1] = temp;
			count++;
			if (count == k){
				comprise = 'a' + nexta;
				cout << comprise << endl;
				return 0;
			}
		}
		lastpos--;
	}

	//z开头第一个
	if (count == k){
		comprise = 'z' + nextz;
		cout << comprise << endl;
		return 0;
	}
	count++;

	//z开头

	lastpos = nextz.size() - 1;
	for (int i = n - 1; i >= 0; i--){
		int j = i;
		for (; j < lastpos; j++){
			char temp;
			temp = nextz[j];
			nextz[j] = nextz[j + 1];
			nextz[j + 1] = temp;
			count++;
			if (count == k){
				comprise = 'z' + nextz;
				cout << comprise << endl;
				return 0;
			}

		}
		lastpos--;
	}
	cout << -1 << endl;
	return 0;
}