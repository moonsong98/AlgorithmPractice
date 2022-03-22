#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

void add(vector<long long> &tree, int pos, long long diff) {
	while(pos<sz(tree)) {
		tree[pos]+=diff;
		pos+=(pos&-pos);
	}
}

long long sum(vector<long long> &tree, int pos) {
	long long ret=0;
	while(pos>0) {
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<long long> arr(n), tmp(n), tree(n+1, 0);
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
		tmp[i]=arr[i];
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for(int i=0; i<n; ++i) {
		arr[i]=lower_bound(tmp.begin(), tmp.end(), arr[i])-tmp.begin()+1;
		cout << i-sum(tree, arr[i]-1)+1 << '\n';
		add(tree, arr[i], 1);
	}
}