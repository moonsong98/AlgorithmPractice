#include<bits/stdc++.h>

using namespace std;

const int INF=1e9+7;

int init(vector<int> &arr, vector<int> &tree, int node, int left, int right) {
	if(left==right) return tree[node]=arr[left];
	int mid=left+(right-left)/2;
	return tree[node]=min(init(arr,tree,node*2,left,mid), init(arr,tree,node*2+1,mid+1,right));
}

int query(vector<int> &tree, int node, int left, int right, int nodeLeft, int nodeRight) {
	if(right<nodeLeft||nodeRight<left) return INF;
	if(left<=nodeLeft&&nodeRight<=right) return tree[node];
	int mid=nodeLeft+(nodeRight-nodeLeft)/2;
	return min(query(tree,node*2,left,right,nodeLeft,mid), query(tree,node*2+1,left,right,mid+1,nodeRight));
}

/* TLE
typedef pair<int,int> pii;
const int NEGINF=-INF;
pii init(vector<int> &arr, vector<pii> &tree, int node, int left, int right) {
	if(left==right) tree[node].first=tree[node].second=arr[left];
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
	if(right<nodeLeft || nodeRight<left) return {INF, NEGINF};
	if(left<=nodeLeft&&nodeRight<=right) return tree[node];
	pii ret;
	int mid=nodeLeft+(nodeRight-nodeLeft)/2;
	pii leftResult=query(tree, node*2, left, right, nodeLeft, mid);
	pii rightResult=query(tree, node*2+1, left, right, mid+1, nodeRight);
	ret.first=min(leftResult.first, rightResult.first);
	ret.second=max(leftResult.second, rightResult.second);
	return ret;
}
*/

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	int h=(int)ceil(log2(n));
	vector<int> arr(n);
	vector<int> treeMin(1<<(h+1));
	vector<int> treeMax(1<<(h+1));
	for(int &a: arr) cin >> a;
	init(arr,treeMin,1,0,n-1);
	for(int &a: arr) a*=-1;
	init(arr,treeMax,1,0,n-1);
	for(int i=0; i<q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << query(treeMin, 1, l-1, r-1, 0, n-1) << ' ' << -query(treeMax,1,l-1,r-1,0,n-1) << '\n';
	}
}