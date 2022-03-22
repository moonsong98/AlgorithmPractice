#include<bits/stdc++.h>

using namespace std;
const int SIZE=1e6+1;

int sum(vector<int> &tree, int pos) {
	int ret=0;
	while(pos>0){
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}

void add(vector<int> &tree, int pos, int diff) {
	while(pos<SIZE) {
		tree[pos]+=diff;
		pos+=(pos&-pos);
	}
}

int kth(vector<int> &tree, int k) {
	int l=1, r=SIZE-1, ret;
	while(l<=r) {
		int mid=l+(r-l)/2;
		if(sum(tree, mid)>=k) {
			ret=mid;
			r=mid-1;
		} else l=mid+1;
	}
	assert(ret>0);
	add(tree, ret, -1);
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<int> tree(SIZE,0);
	int q; cin >> q;
	while(q--) {
		int a;
		cin >> a;
		if(a==1) {
			int b;
			cin >> b;
			cout << kth(tree, b) << '\n';
		}
		if(a==2) {
			int b, c;
			cin >> b >> c;
			add(tree, b, c);
		}
	}
}