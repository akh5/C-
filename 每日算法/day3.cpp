/**
��Ŀ����
�ֵ��˷��յļ��ڣ�ǡ��С��ȥţţ�Ĺ�԰�����档
ţţ��˵����������԰��ÿ���ط�������ָ�ƣ�С�ײ�̫���ţ��������뿼��ţţ��
�ڹ�԰����N��ƻ����ÿ��ƻ��������Ϊai��С��ϣ��֪��������������x��ƻ����������һ�ѵġ�
ţţ�����������̫�򵥣�����ϣ�����������ش�
��������:
��һ��һ����n(1 <= n <= 105)��
�ڶ���n����ai(1 <= ai <= 1000)����ʾ������������i���ж���ƻ��
������һ����m(1 <= m <= 105)����ʾ��m��ѯ�ʡ�
������m����qi����ʾС��ϣ��֪����qi��ƻ��������һ�ѡ�
�������:
m�У���i�������qi��ƻ��������һ�ѡ�
ʾ��1
����
����
5
2 7 3 4 9
3
1 25 11
���
����
1
5
3
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> apples(n);
	vector<int> suma(n);
	for (int a = 0; a < n; a++){
		cin >> apples[a];
	}
	int sum=0;
	for (int a = 0; a < n; a++){
		sum += apples[a];
		suma[a] = sum;
	}
	int m;
	cin >> m;
	vector<int> guess(m);
	for (int i = 0; i < m; i++){
		cin >> guess[i];
	}
	int x = 0;
	int y = 0;
	while( y< m){
		if (guess[y] >suma[x]){
			x++;
		}
		else{
			y++;
			cout << x+1 << endl;
			x = 0;
		}
	}


	return 0;
}