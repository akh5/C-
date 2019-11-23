#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	/*
	int w, h;
	cin >> w >> h;

	if (w % 2 + h % 2 == 1 || w % 2 + h % 2 == 2){
		cout << (w*h / 2) + w % 2 + h % 2 - 1;
	}
	if (w % 2 + h % 2 == 0){
		cout << (w*h / 2) + w % 2 + h % 2;
	}
	*/
	int W, H;
	cin >> W >> H;
	
		int cnt = 0;
		if (W % 4 == 0 || H % 4 == 0)
			cnt = W*H / 2;
		else if (W % 2 == 0 && H % 2 == 0)
			cnt = (W*H / 4 + 1) * 2;
		else
			cnt = W*H / 2 + 1;
		cout << cnt << endl;
	
	return 0;
}