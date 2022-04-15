#include<bits/stdc++.h>
#define p first
#define t second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int K, M, N; cin >> K >> M >> N;
	vector<ll> f(M), s1(M+1), s2(M+1);
	vector<pll> v(K);
	
	for(int i=0; i<K; ++i)
		cin >> v[i].p >> v[i].t;
	for(int i=0; i<M; ++i)
		cin >> f[i];
	f.push_back(-1);
	f.push_back((ll)1e9+7);
	sort(all(v));
	sort(all(f));
	for(int i=0, vp=0; i<=M; ++i) {
		ll f1=f[i], f2=f[i+1], sum=0;
		ll range=f2-f1;
		queue<ll> q;
		while(vp<sz(v)&&v[vp].p<f2) {
			s1[i]+=v[vp].t;
			while(!q.empty()&&range<=2*(v[vp].p-v[q.front()].p)) {
				sum-=v[q.front()].t;
				q.pop();
			}
			q.push(vp);
			sum+=v[vp].t;
			s2[i]=max(s2[i], sum);
			++vp;
		}
	}
	vector<ll> val;
	for(int i=0; i<=M; ++i) {
		val.push_back(s2[i]);
		val.push_back(s1[i]-s2[i]);
	}
	sort(all(val), [](ll a, ll b){return a>b;});
	ll ans=0;
	for(int i=0; i<N; ++i)
		ans+=val[i];
	cout << ans << '\n';
}