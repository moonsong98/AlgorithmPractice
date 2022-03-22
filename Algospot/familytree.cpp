#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF=1e9+7;

vvi adj;
vi seq;
vi depth;
vi tree;
vi initPos;

void traversal(int u, int d) {
	initPos[u]=sz(seq);
	seq.push_back(u);
	depth[u]=d;
	for(int v: adj[u]) {
		traversal(v, d+1);
		seq.push_back(u);
	}
}

int init(int node, int left, int right) {
	if(left==right) return tree[node]=depth[seq[left]];
	int mid=left+(right-left)/2;
	int leftResult=init(node*2, left, mid);
	int rightResult=init(node*2+1, mid+1, right);
	return tree[node]=min(leftResult, rightResult);
}

int query(int node, int left, int right, int nodeLeft, int nodeRight) {
	if(right<nodeLeft||nodeRight<left) return INF;
	if(left<=nodeLeft&&nodeRight<=right) return tree[node];
	int mid=nodeLeft+(nodeRight-nodeLeft)/2;
	int leftResult=query(node*2, left, right, nodeLeft, mid);
	int rightResult=query(node*2+1, left, right, mid+1, nodeRight);
	return min(leftResult, rightResult);
}

void solve() {
	int n, q;
	cin >> n >> q;
	seq.clear();
	adj=vvi(n);
	initPos=vi(n,-1);
	depth=vi(n);
	for(int i=1; i<n; ++i) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	traversal(0, 0);
	int lenSeq=sz(seq);
	tree=vi(1<<((int)ceil(log2(lenSeq))+1));
	init(1, 0, lenSeq-1);
	for(int i=0; i<q; ++i) {
		int a, b;
		cin >> a >> b;
		if(initPos[a]>initPos[b]) {
			int t=a;
			a=b;
			b=t;
		}
		int lca=query(1,initPos[a],initPos[b],0,lenSeq-1);
		cout << depth[a]+depth[b]-2*lca<<'\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
		solve();
}