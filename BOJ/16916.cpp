#include<bits/stdc++.h>

using namespace std;

int main(void) {
	string str, cmpStr;
	cin >> str >> cmpStr;
	vector<int> pi(cmpStr.size(), 0);
	for(int i=1, j=0; i<cmpStr.size(); ++i) {
		while(j>0 && cmpStr[i]!=cmpStr[j]) j=pi[j-1];
		if(cmpStr[i]==cmpStr[j]) pi[i]=++j;
	}
	for(int i=0, j=0; i<str.size(); ++i) {
		while(j>0&&str[i]!=cmpStr[j]) j=pi[j-1];
		if(str[i]==cmpStr[j]) {
			++j;
			if(j==cmpStr.size()) {
				cout << 1 << '\n';
				return  0;
			}
		}
	}
	cout << 0 << '\n';
}