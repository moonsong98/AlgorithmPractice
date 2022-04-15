#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> pSum1(n+1), pSum2(n+1), pSum3(n+1);
	for(int i=1; i<=n; ++i) {
		pSum1[i]=pSum1[i-1];
		pSum2[i]=pSum2[i-1];
		pSum3[i]=pSum3[i-1];
		int a;
		cin >> a;
		if(a==1) ++pSum1[i];
		else if(a==2) ++pSum2[i];
		else if(a==3) ++pSum3[i];
	}
	for(int i=0; i<q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << pSum1[r]-pSum1[l-1] << ' ' << pSum2[r]-pSum2[l-1] << ' ' << pSum3[r]-pSum3[l-1] << '\n';
	}
}