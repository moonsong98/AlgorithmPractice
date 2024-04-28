#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
const int INF=1e9+7;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi adj;
vi depth, initPos, seq, tree;

void traversal(int u, int d) {
	initPos[u]=sz(seq);
	depth[u]=d;
	seq.push_back(u);
	for(int v:adj[u])
		if(initPos[v]==-1){
			traversal(v, d+1);
			seq.push_back(u);
		}
}

int init(int node, int left, int right) {
	if(left==right) return tree[node]=seq[left];
	int mid=left+(right-left)/2;
	int leftResult=init(node*2, left, mid);
	int rightResult=init(node*2+1, mid+1, right);
	if(depth[leftResult]<depth[rightResult]) return tree[node]=leftResult;
	else return tree[node]=rightResult;
}

int query(int node, int left, int right, int nodeLeft, int nodeRight) {
	if(right<nodeLeft||nodeRight<left) return -1;
	if(left<=nodeLeft&&nodeRight<=right) return tree[node];
	int mid=nodeLeft+(nodeRight-nodeLeft)/2;
	int leftResult=query(node*2, left, right, nodeLeft, mid);
	int rightResult=query(node*2+1, left, right, mid+1, nodeRight);
	if(leftResult==-1) {
		if(rightResult==-1) return -1;
		return rightResult;
	}
	if(rightResult==-1) return leftResult;
	if(depth[leftResult]<depth[rightResult]) return leftResult;
	else return rightResult;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	adj=vvi(N+1);
	initPos=vi(N+1, -1);
	depth=vi(N+1);
	for(int i=0; i+1<N; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	traversal(1, 0);
	int lenSeq=sz(seq);
	tree=vi(1<<((int)ceil(log2(lenSeq))+1));
	init(1,0,lenSeq-1);
	int q;
	cin >> q;
	for(int i=0; i<q; ++i) {
		int l, r;
		cin >> l >> r;
		if(initPos[l]>initPos[r]) {
			int t=l; l=r; r=t;
		}
		cout << query(1, initPos[l], initPos[r], 0, lenSeq-1) << '\n';
	}
}