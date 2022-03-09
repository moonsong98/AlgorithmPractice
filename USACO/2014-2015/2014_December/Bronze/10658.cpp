#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define sz(x) (int)x.size()
typedef long long ll;

using namespace std;

ll INF=1e10+7;

void solve() {
	ll N, A, B, ans=0;
	cin >> N >> A >> B;
	vector<pair<ll, bool>> seq(1, {-INF, false});
	for(int i=0; i<N; ++i) {
		char s[2];
		ll p;
		cin >> s >> p;
		seq.emplace_back(p, s[0]=='S');
	}
	seq.emplace_back(INF,false);
	sort(seq.begin(), seq.end());
	for(int i=0; i+1<sz(seq); ++i) {
		ll s=seq[i].first, e=seq[i+1].first, mid=s+(e-s)/2;
		bool ss=seq[i].second, ee=seq[i+1].second;
		if(ss) {
			ll S=max(s+1, A), E=min(mid, B);
			if(S<=E) {
				ans+=E-S+1;
			}
		}
		if(ee) {
			ll S=max(mid+1, A), E=min(e, B);
			if(S<=E) {
				ans+=E-S+1;
			}
		}
		if(ee&&!ss&&(e-s)%2==0&&A<=mid&&mid<=B) ++ans;
	}
	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}