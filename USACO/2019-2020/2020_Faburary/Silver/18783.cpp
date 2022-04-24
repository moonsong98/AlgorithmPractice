#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

void getBin(vector<int>& bin, int t, int k) {
	while(t>=0) {
		if((1<<t)<=k) {
			k-=(1<<t);
			bin.push_back(1);
		} 
		else bin.push_back(0);
		--t;
	}
}

int main(void) {
	int n, m, k, t=1;
	cin >> n >> m >> k;
	vector<int> v(n);
	vector<int> bin;
	vector<vector<int>> op;
	for(int i=0; i<n; ++i) v[i]=i+1;
	for(int i=0; i<m; ++i) {
		int l, r; cin >> l >> r;
		reverse(v.begin()+(l-1), v.begin()+r);
	}
	while(k>=(1<<t)) ++t;
	--t;
	getBin(bin, t, k);
	for(int i=sz(bin)-1; i>=0; --i) {
		if(i==sz(bin)-1){
			if(bin[i]==1) op.push_back(v);
			continue;
		}
		vector<int> nxt(n);
		for(int i=0; i<n; ++i)
			nxt[i]=v[v[i]-1];
		if(bin[i])
			op.push_back(nxt);
		v=nxt;
	}
	vector<int> ans(n);
	for(int i=0; i<n; ++i) ans[i]=i+1;
	for(auto vv: op) {
		vector<int> nxt(n);
		for(int i=0; i<n; ++i)
			nxt[i]=ans[vv[i]-1];
		ans=nxt;
	}
	for(int a: ans) cout << a << '\n';
}