#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;

int main(void) {
	int n;
	cin >> n;
	stack<ll> s;
	ll ans=0;
	for(int i=0; i<n; ++i) {
		ll a; cin >> a;
		int cnt=0;
		while(!s.empty()&&a>s.top()) {
			ans+=2;
			s.pop();
		}
		ans+=cnt;
		s.push(a);
	}
	ll st=s.empty()?0:s.top();
	ll cnt=0;
	while(!s.empty()) {
		if(st!=s.top()) break;
		++cnt;
		s.pop();
	}
	ans+=cnt*(cnt-1)/2;
	cout << ans << '\n';
}