#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

int sum(vector<int> &tree, int pos) {
	int ret=0;
	while(pos>0) {
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}

void add(vector<int> &tree, int pos, int diff) {
	while(pos<sz(tree)) {
		tree[pos]+=diff;
		pos+=(pos&-pos);
	}
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> pos(n+1), tree(n+m+1);
		for(int i=1; i<=n; ++i) {
			pos[i]=m+i;
			add(tree,pos[i],1);
		}
		while(m--) {
			int a;
			cin >> a;
			cout << sum(tree, pos[a])-1 << ' ';
			add(tree,pos[a],-1);
			pos[a]=m+1;
			add(tree,pos[a],1);
			
		}
		cout << '\n';
	}
}