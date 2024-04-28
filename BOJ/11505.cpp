#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M=1e9+7;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int left, int right) {
	if(left==right) return tree[node]=arr[left];
	int mid=left+(right-left)/2;
	return tree[node]=init(arr, tree, node*2, left, mid) * init(arr, tree, node*2+1, mid+1, right) % M;
}

ll mul(vector<ll> &tree, int node, int left, int right, int nodeLeft, int nodeRight) {
	if(right<nodeLeft||nodeRight<left) return 1;
	if(left<=nodeLeft&&nodeRight<=right) return tree[node];
	int mid=nodeLeft+(nodeRight-nodeLeft)/2;
	return mul(tree,node*2,left,right,nodeLeft,mid)*mul(tree,node*2+1,left,right,mid+1,nodeRight)%M;
}

ll update(vector<ll> &tree, int node, int left, int right, int idx, ll newValue) {
	if(idx<left||right<idx) return tree[node];
	if(left==right) return tree[node]=newValue;
	int mid=left+(right-left)/2;
	return tree[node]=update(tree, node*2, left, mid, idx, newValue)*update(tree, node*2+1, mid+1, right, idx, newValue)%M;
}

void print(vector<ll> &tree, int node, int left, int right) {
	if(left==right) return;
	print(tree, node*2, left, (right+left)/2);
	print(tree, node*2+1, (right+left)/2+1, right);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	int h=(int)ceil(log2(n));
	vector<ll> arr(n);
	vector<ll> tree(1<<(h+1));
	for(ll &a: arr) cin >> a;
	init(arr,tree,1,0,n-1);
	for(int i=0; i<m+k; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		if(a==1) update(tree, 1, 0, n-1, b-1, c);
		if(a==2) cout << mul(tree, 1, b-1, c-1, 0, n-1) << '\n';
	}
	print(tree, 1, 0, n-1);
}
