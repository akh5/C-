#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
	string str1, str2;
	while (cin >> str1 >> str2){
		int maxlen = 0;
		int len = 0;
		int o=0,maxo;
		if (str1.length() < str2.length()){
			string temp = str1;
			str1=str2;
			str2 = temp;
			
		}
		vector<string> out(str1.length());
		for (int i = 0; i < str1.length(); i++){
			int tempi = i;
			for (int j = 0; j < str2.length(); j++){
				if (str1[tempi] == str2[j]){
					out[o].push_back(str2[j]);
					len++;
					tempi++;
				}
				else{
					if ( len >= 1){
						break;
					}
				}
				if (len>maxlen){
					maxlen = len;
					maxo = o;
				}
			}
			len = 0;
			o++;
		}
		cout << out[maxo] << endl;
		
	}

	return 0;
}