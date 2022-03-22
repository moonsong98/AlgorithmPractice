#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int main() {
	string str, revStr;
	cin >> revStr;
	str=string(revStr.rbegin(), revStr.rend());
	vector<int> fail(sz(revStr), 0);
	for(int i=1, j=0; i<sz(revStr); ++i) {
		while(j>0&&revStr[i]!=revStr[j]) j=fail[j-1];
		if(revStr[i]==revStr[j])
			fail[i]=++j;
	}
	for(int i=0, j=0; i<sz(str); ++i) {
		while(j>0&&str[i]!=revStr[j]) j=fail[j-1];
		if(str[i]==revStr[j]) {
			++j;
			if(i==sz(str)-1){
				cout << sz(str)+sz(str)-j << '\n';
				return 0;
			}
		}
	}
}