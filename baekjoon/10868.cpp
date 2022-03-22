#include<bits/stdc++.h>

using namespace std;

const int INF=1e9+7;

int init(vector<int>& arr, vector<int>& tree, int node, int left, int right) {
	if(left==right) return tree[node]=arr[left];
	int mid=left+(right-left)/2;
	return tree[node]=min(init(arr,tree,node*2, left, mid), init(arr,tree,node*2+1, mid+1, right));
}

int query(vector<int> &tree, int node, int left, int right, int nodeLeft, int nodeRight) {
	if(nodeRight<left||right<nodeLeft) return INF;
	if(left<=nodeLeft&&nodeRight<=right) return tree[node];
	int mid=nodeLeft+(nodeRight-nodeLeft)/2;
	return min(query(tree,node*2,left,right,nodeLeft, mid), query(tree,node*2+1,left,right,mid+1, nodeRight));
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int h=(int)ceil(log2(n));
	vector<int> arr(n), tree(1<<(h+1));
	for(int i=0; i<n; ++i) cin >> arr[i];
	init(arr,tree,1,0,n-1);
	for(int i=0; i<m; ++i) {
		int l, r;
		cin >> l >> r;
		cout << query(tree,1,l-1,r-1,0,n-1) << '\n';
	}
}
