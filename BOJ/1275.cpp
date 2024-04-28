#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;

ll sum(vector<ll> &tree, int pos) {
	ll ret=0;
	while(pos>0) {
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}

void add(vector<ll> &tree, int pos, ll diff) {
	while(pos<sz(tree)) {
		tree[pos]+=diff;
		pos+=(pos&-pos);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, Q;
	cin >> N >> Q;
	vector<ll> arr(N+1), tree(N+1);
	for(int i=1; i<=N; ++i) {
		cin >> arr[i];
		add(tree, i, arr[i]);
	}
	for(int i=0; i<Q; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (b>a?sum(tree, b)-sum(tree, a-1):sum(tree,a)-sum(tree,b-1)) << '\n';
		ll diff=d-arr[c];
		arr[c]=d;
		add(tree,c,diff);
	}
}