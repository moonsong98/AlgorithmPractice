#include<bits/stdc++.h>
using namespace std;

vector<bool> taken;
vector<int> v, ans;
int n;
bool valid=false;

void solve(int pos) {
	if(pos==n) {
		for(int num: ans) cout << num << ' ' ;
		cout << '\n';
		valid=true;
		return;
	}
	for(int i=1; i<=n; ++i) {
		if(valid) return;
		if(taken[i]||v[pos]==i) continue;
		ans.push_back(i);
		taken[i]=true;
		solve(pos+1);
		ans.pop_back();
		taken[i]=false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		valid=false;
		cin >> n;
		v=vector<int>(n);
		ans=vector<int>();
		taken=vector<bool>(n+1, false);
		for(int i=0; i<n; ++i) cin >> v[i];
		solve(0);
		if(!valid) cout << -1 << '\n';
	}
}