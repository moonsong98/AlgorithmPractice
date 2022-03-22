#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int NEGINF=-1e9;
const int INF=1e9;

pii init(vector<int>& arr, vector<pii>& tree, int node, int left, int right) {
	if(left==right)
		tree[node].first=tree[node].second=arr[left];
	else {
		int mid=left+(right-left)/2;
		pii leftResult=init(arr, tree, node*2, left, mid);
		pii rightResult=init(arr, tree, node*2+1, mid+1, right);
		tree[node].first=min(leftResult.first, rightResult.first);
		tree[node].second=max(leftResult.second, rightResult.second);
	}
	return tree[node];
}

pii query(vector<pii> &tree, int node, int left, int right, int nodeLeft, int nodeRight) {
	if(nodeRight<left || nodeLeft>right) return {INF, NEGINF};
	if(left<=nodeLeft&&nodeRight<=right) return tree[node];
	pii ret;
	int mid=nodeLeft+(nodeRight-nodeLeft)/2;
	pii leftResult=query(tree, node*2, left, right, nodeLeft, mid);
	pii rightResult=query(tree, node*2+1, left, right, mid+1, nodeRight);
	ret.first=min(leftResult.first, rightResult.first);
	ret.second=max(leftResult.second, rightResult.second);
	return ret;
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		int h=(int)ceil(log2(n));
		vector<int> arr(n);
		vector<pii> tree(1<<(h+1));
		for(int &num: arr) cin >> num;
		init(arr, tree, 1, 0, n-1);
		for(int i=0; i<q; ++i) {
			int l, r;
			cin >> l >> r;
			pii ret=query(tree, 1, l, r, 0, n-1);
			cout << ret.second-ret.first << '\n';
		}
	}
}