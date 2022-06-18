#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int t; cin >> t;
	while(t--) {
		int a, b; 
		cin >> a >> b;
		string ans;
		if(a>b) {
			ans+='0'; --a;
			while(a>0&&b>0) {
				ans+="10";
				--a;--b;
			}
		}
		else if (a<=b) {
			ans+='1'; --b;
			while(a>0&&b>0) {
				ans+="01";
				--a;--b;
			}
		}
		while(a>0) {
			ans+='0';
			--a;
		}
		while(b>0) {
			ans+='1';
			--b;
		}
		cout << ans << '\n';
	}
}