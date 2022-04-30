#include<bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		if(a==1||b==1) {
			if(a>2 || b>2) cout << -1 << '\n';
			else cout << abs(a-b) << '\n';
		}
		else cout << a+b-2+abs(a-b)-abs(a-b)%2 << '\n';
	}
}