#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct FWT {
	int n;
	vector<ll> tree;
	FWT(int _n):n(_n), tree(_n+1){}
	ll sum(int pos) {
		ll ret=0;
		while(pos>0) {
			ret+=tree[pos];
			pos-=(pos&-pos);
		}
		return ret;
	}
	void add(int pos, ll val) {
		while(pos<=n) {
			tree[pos]+=val;
			pos+=(pos&-pos);
		}
	}
	void update(int pos, ll val) {
		ll diff=val-sum(pos)+sum(pos-1);
		add(pos, diff);
	}
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	FWT* fwt=new FWT(n);
	for(int i=1; i<=n; ++i) {
		ll a;
		cin >> a;
		fwt->add(i, a);
	}
	for(int i=0; i<k+m; ++i) {
		int a;
		ll b, c;
		cin >> a >> b >> c;
		if(a==1)
			fwt->update(b, c);
		if(a==2) {
			ll ub=fwt->sum(c), lb=fwt->sum(b-1);
			cout << ub-lb << '\n';
		}
	}
}