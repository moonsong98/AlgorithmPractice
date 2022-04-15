#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;

int main(void) {
	int n;
	cin >> n;
	stack<pil> s;
	vector<pil> v;
	ll ans=0;
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		if(v.empty()||v.back().first!=a) v.push_back({a, 1ll});
		else v.back().second++;
	}
	for(int i=0; i<sz(v); ++i) {
		while(!s.empty()&&s.top().first<v[i].first) {
			ll c=s.top().second;
			ans+=((c*(c-1))/2+c);
			s.pop();
		}
		if(!s.empty()) {
			ans+=v[i].second;
			if(s.top().first==v[i].first) {
				auto st=s.top();
				s.pop();
				s.push({st.first, st.second+v[i].second});
				continue;
			}
		}
		if(s.empty())
			ans+=v[i].second-1;
		s.push(v[i]);
	}
	while(!s.empty()) {
		ll c=s.top().second;
		ans+=(c*(c-1))/2;
		s.pop();
	}
	cout << ans << '\n';
}