#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A, B, C;
	A = (a + c) / 2;
	B = (b + d) / 2;
	C = B - b;
	if (A - B == a&&B - C == b&&A + B == c&&B + C == d){
		cout << A << " " << B << " " << C;
	}
	else{
		cout << "No";
	}

	return 0;
}