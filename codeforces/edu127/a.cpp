#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		string str;
		cin >> str;
		int cnt=1;
		char ch=str[0];
		for(int i=1; i<sz(str); ++i) {
			if(ch!=str[i]) {
				if(cnt==1) break;
				cnt=1;
				ch=str[i];
			}
			else ++cnt;
		}
		cout << (cnt==1?"NO":"YES") << '\n';
	}
}