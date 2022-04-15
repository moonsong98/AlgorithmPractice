#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	ll ans=0, curSlope=0, curY=-1e9, cur=0;
	int N; cin >> N;
	map<ll, int> trackSlope;
	
	for(int i=0; i<N; ++i) {
		ll a, b;
		cin >> a >> b;
		cur+=abs(a-b);
		if(abs(a)>abs(a-b)) continue;
		trackSlope[b]+=2;
		if(a<0&&a<b||a>=0&&a>=b) {
			trackSlope[0]--;
			trackSlope[2*b]--;
		}
		if(a<0&&a>=b||a>=0&&a<b) {
			trackSlope[2*a]--;
			trackSlope[2*b-2*a]--;
		}
	}
	ans=cur;
	for(auto p: trackSlope) {
		ll y=p.first, deltaSlope=p.second;
		cur+=curSlope*(y-curY);
		curY=y;
		curSlope+=deltaSlope;
		ans=min(ans,cur);
	}
	cout << ans << '\n';
}