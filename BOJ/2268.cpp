#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll tree, arr;

ll sum(int pos) {
	ll ret=0;
	while(pos>0){
		ret+=tree[pos];
		pos-=(pos&-pos);
	}
	return ret;
}

void update(int pos, int diff) {
	while(pos<(int)tree.size()) {
		tree[pos]+=diff;
		pos+=(pos&-pos);
	}
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	tree=vll(n+1);
	arr=vll(n+1);
	while(m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if(a==0) {
			cout << (c>b? sum(c)-sum(b-1):sum(b)-sum(c-1) )<< '\n';
		}
		else {
			update(b, c-arr[b]);
			arr[b]=c;
		}
	}
}