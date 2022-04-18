#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a, b;

void swap(int i) {
	int t=a[i+1];
	a[i+1]=b[i+1];
	b[i+1]=t;
}

int main(void){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int N; cin >> N;
		ll ans=0;
		a=vector<ll>(N);
		b=vector<ll>(N);
		for(ll& n: a) cin >> n;
		for(ll& n: b) cin >> n;
		for(int i=0; i+1<N; ++i) {
			if(abs(a[i]-a[i+1])+abs(b[i]-b[i+1])>abs(a[i]-b[i+1])+abs(b[i]-a[i+1])) swap(i);
			ans+=abs(a[i]-a[i+1])+abs(b[i]-b[i+1]);
		}
		cout << ans << '\n';
	}
}