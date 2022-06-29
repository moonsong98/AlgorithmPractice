#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	int tt; cin >> tt;
	while(tt--) {
		int n, k; 
		string str;
		cin >> n >> k >> str;
		vector<int> moves;
		long long ans=0;
		int l=1e9+7, r=-1, numOnes=0;
		for(int i=0; i<n; ++i) {
			if(str[i]=='1') {
				ans+=11;
				l=min(l, i);
				r=max(r, i);
				++numOnes;
			}
		}
		if(n-(r+1)<=k&&numOnes) {
			k-=(n-(r+1));
			ans-=10;
			--numOnes;
		}
		if(l<=k&&numOnes)
			ans-=1;
		cout << ans << '\n';
	}
}