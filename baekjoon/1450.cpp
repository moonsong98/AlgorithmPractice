#include<iostream>
#include<vector>
#include<algorithm>
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;

int main(void) {
	int N, C;
	cin >> N >> C;
	int half=N/2;	
	vector<ll> P(N);
	for(ll &p: P)
		cin >> p;
	vector<ll> fh(1<<half), sh(1<<(N-half));
	for(int i=0; i<half; ++i)
		for(int j=0; j<(1<<half); ++j)
			if(j&(1<<i))
				fh[j]+=P[i];
	for(int i=0; i<N-half; ++i)
		for(int j=0; j<(1<<(N-half)); ++j)
			if(j&(1<<i))
				sh[j]+=P[i+half];
	sort(all(sh));
	ll ans=0;
	for(ll f: fh) {
		auto ub=upper_bound(all(sh),C-f);
		ans+=ub-sh.begin();
	}
	cout << ans << '\n';
}