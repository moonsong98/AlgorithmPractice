#include<bits/stdc++.h>
using namespace std;

int main(void){
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		int maxel=-1;
		for(int i=0; i<n; ++i) {
			cin >> v[i];
			maxel=max(maxel, v[i]);
		}
		long long ans=llong_max;
		for(int m=maxel; m<=maxel+1; ++m) {
			long long numodd=0, numeven=0;
			for(int i=0; i<n; ++i) {
				numodd+=(long long)(m-v[i])%2;
				numeven+=(long long)(m-v[i])/2;
			}
			if(numodd>numeven) ans=min(ans, numodd*2-1);
			else {
				long long q=(numodd+numeven*2)/3;
				long long r=(numodd+numeven*2)%3;
				numeven=q+(r==2);
				numodd=q+(r==1);
				if(numeven>=numodd) ans=min(ans, numeven*2);
				else ans=min(ans, numodd*2-1);
			}
		}
		cout << ans << '\n';
	}
}