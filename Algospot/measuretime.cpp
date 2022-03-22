#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

long long sum(vector<long long> &tree, int idx) {
	long long ret=0;
	while(idx>0) {
		ret+=tree[idx];
		idx-=(idx&-idx);
	}
	return ret;
}

void add(vector<long long> &tree, int idx) {
	while(idx<sz(tree)) {
		tree[idx]++;
		idx+=(idx&-idx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<long long> tree(n+1);
		vector<int> seq(n), tmp(n);
		for(int i=0; i<n; ++i) {
			cin >> seq[i];
			tmp[i]=seq[i];
		}
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		for(int i=0; i<n; ++i)
			seq[i]=lower_bound(tmp.begin(), tmp.end(), seq[i])-tmp.begin()+1;
		long long ans=0;
		for(int s: seq) {
			ans+=sum(tree, n)-sum(tree, s);
			add(tree, s);
		}
		cout << ans << '\n';
	}
}