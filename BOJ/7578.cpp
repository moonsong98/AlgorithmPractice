#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

vector<long long> tree;
int sum(int pos) {
	long long ret=0;
	while(pos>0) {
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}
void add(int pos) {
	while(pos<sz(tree)) {
		tree[pos]++;
		pos+=(pos&-pos);
	}
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	map<int, int> m;
	for(int i=1; i<=n; ++i) {
		int a;
		cin >> a;
		m[a]=i;
	}
	vector<int> arr;
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		arr.push_back(m[a]);
	}
	tree=vector<long long>(n+1);
	long long ans=0;
	for(int i=0; i<n; ++i) {
		ans+=sum(n)-sum(arr[i]);
		add(arr[i]);
	}
	cout << ans << '\n';
}