#include<bits/stdc++.h>
#define sz(x) x.size()

using namespace std;

vector<long long> tree;

long long sum(int idx) {
	long long ret=0;
	while(idx>0) {
		ret+=tree[idx];
		idx-=(idx&-idx);
	}
	return ret;
}

void add(int idx) {
	while(idx<sz(tree)) {
		tree[idx]++;
		idx+=(idx&-idx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> seq(n);
	vector<int> tmp(n);
	for(int i=0; i<n; ++i){
		cin >> seq[i];
		tmp[i]=seq[i];
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()),tmp.end());
	for(int i=0; i<n; ++i)
		seq[i]=lower_bound(tmp.begin(),tmp.end(),seq[i])-tmp.begin()+1;
	reverse(seq.begin(), seq.end());
	tree=vector<long long>(n+1, 0);
	long long ans=0;
	for(int s: seq) {
		ans+=sum(s-1);
		add(s);
	}
	cout << ans << '\n';
}