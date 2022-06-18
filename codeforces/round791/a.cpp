#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll min=-1, max=-1;
		if(n%4==0) max=n/4;
		else if((n-6)%4==0&&n>=6) max=(n-6)/4+1;
		if(n%6==0) min=n/6;
		else if((n-4)%6==0&&n>=4) min=(n-4)/6+1;
		else if((n-8)%6==0&&n>=8) min=(n-8)/6+2;
		if(min==-1&&max==-1) cout << -1 << '\n';
		else if(min==-1) cout << max << ' ' << max << '\n';
		else if(max==-1) cout << min << ' ' << min << '\n';
		else cout << min << ' ' << max << '\n';
	}
}