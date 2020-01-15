//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector <vector<int>> trangle(n, vector<int>(2 * n ));
//	trangle[0][1] = 1;
//	//构建杨辉三角形
//	for (int i = 1; i < n; i++) //i代表层
//	{
//		trangle[i][0] = 0;
//		trangle[i][1] = 1;
//		trangle[i][2 * (i + 1) - 1] = 1;
//		for (int j = 2; j < 2 * (i+1) - 1; j++){
//			trangle[i][j] = trangle[i - 1][j - 2] + trangle[i - 1][j-1] + trangle[i - 1][j];
//		}
//	}
//	for (int a = 1; a < 2 * n - 1; a++){
//		if (trangle[n - 1][a] % 2 == 0){
//			cout << a << endl;
//			return 0;
//		}
//	}
//	cout << -1 << endl;
//
//	return 0;
//}

//线上OJ循环输入版本
#include <iostream>
#include<vector>
using namespace std;

int main(){
	int n;

	while (cin >> n){
		vector <vector<int>> trangle(n, vector<int>(2 * n));
		trangle[0][1] = 1;
		//构建杨辉三角形
		for (int i = 1; i < n; i++) //i代表层
		{
			trangle[i][0] = 0;
			trangle[i][1] = 1;
			trangle[i][2 * (i + 1) - 1] = 1;
			for (int j = 2; j < 2 * (i + 1) - 1; j++){
				trangle[i][j] = trangle[i - 1][j - 2] + trangle[i - 1][j - 1] + trangle[i - 1][j];
			}
		}
		int a = 1;
		for (; a < 2 * n - 1; a++){
			if (trangle[n - 1][a] % 2 == 0){
				cout << a << endl;
				break;
			}
		}
		if (a == 2 * n - 1){
			cout << -1 << endl;
		}
	}
	return 0;
}