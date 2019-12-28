#include<iostream>
using namespace std;

int Add(int A, int B){
	/*int cArr = 0;
	int result;
	int A, B;
	while (A << 1 || B << 1){
		A = A % 2;
		B = B % 2;

		result = A^B;
	}
	return result;*/
	if (	A == 0)
	{
		return B;
	}
	if (B == 0)
	{
		return A;
	}
	else
	{
		int c = A ^ B;
		int d = (A & B) << 1;
		return Add(c, d);
	}
}


int main(){
	Add(5, 6);
	return 0;
}