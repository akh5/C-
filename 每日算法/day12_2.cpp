#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool chkParenthesis(string A, int n) {
	int flag = 0;
	if (n % 2 == 1){
		return false;
	}
	for (int i = 0; i < A.length() ; i++){
		if (A[i] != '(' && A[i] != ')'){
			return false;
		}
		if (A[i] == '('){
			flag++;
		}
		if (A[i] == ')'){
			flag--;
		}
	}
	if (flag == 0){
		return true;
	}
	else{
		return false;
	}

}


int main(){
	string A;
	int n;
	cin >> A>>n;
	
	cout<<chkParenthesis(A, n);
	
	return 0;
}