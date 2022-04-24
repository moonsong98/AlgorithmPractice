#include<bits/stdc++.h>
using namespace std;

vector<int> tree, v;

int init(int node, int l, int r) {
	if(l==r) return tree[node]=l;
	int mid=l+(r-l)/2;
	int lmin=init(node*2, l, mid);
	int rmin=init(node*2+1, mid+1, r);
	return tree[node]=v[lmin]<=v[rmin]?lmin:rmin;
}

void update(int node, int index, int l, int r) {
	if(index<l||r<index) return;
	if(l==r) return;
	int mid=l+(r-l)/2;
	update(node*2, index, l, mid);
	update(node*2+1, index, mid+1, r);
	tree[node]=v[tree[node*2]]<=v[tree[node*2+1]]?tree[node*2]:tree[node*2+1];
}

int getMin(int node, int lb, int ub, int l, int r) {
	if(ub<l||r<lb) return -1;
	if(lb<=l&&r<=ub) return tree[node];
	int mid=l+(r-l)/2;
	int lmin=getMin(node*2, lb, ub, l, mid);
	int rmin=getMin(node*2+1, lb, ub, mid+1, r);
	if(lmin==-1) return rmin;
	else if(rmin==-1) return lmin;
	return v[lmin]<=v[rmin]?lmin:rmin;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m; cin >> n;
	v=vector<int>(n);
	tree=vector<int>( (1 << ((int)ceil(log2(n)))+1));
	for(int &a: v) cin >> a;
	init(1, 0, n-1);
	cin >> m;
	for(int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a==1) {
			v[b-1]=c;
			update(1, b-1, 0, n-1);
		}
		else
			cout << getMin(1, b-1, c-1, 0, n-1)+1 << '\n';
	}
	
}