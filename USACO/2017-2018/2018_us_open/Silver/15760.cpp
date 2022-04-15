#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

void add(vector<int>& tree, int pos) {
	while(pos<sz(tree)) {
		tree[pos]++;
		pos+=(pos&-pos);
	}
}
int sum(vector<int>& tree, int pos) {
	int ret=0;
	while(pos>0) {
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	vector<int> tmp(N), arr(N), tree(N+1);
	for(int i=0; i<N; ++i) {
		cin >> arr[i];
		tmp[i]=arr[i];
	}
	sort(tmp.begin(), tmp.end());
	for(int i=0; i<N; ++i) 
		arr[i]=lower_bound(tmp.begin(), tmp.end(), arr[i])-tmp.begin()+1;
	int ans=-1;
	for(int i=0; i<N; ++i) {
		ans=max(ans,sum(tree,N)-sum(tree,arr[i])+1);
		add(tree, arr[i]);
	}
	cout << ans << '\n';
}