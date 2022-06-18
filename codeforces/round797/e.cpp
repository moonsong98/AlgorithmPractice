#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		long long sum=0;
		vector<int> mod(k, 0);
		for(int i=0; i<n; ++i) {
			long long num;
			cin >> num;
			sum+=num;
			mod[num%k]++;
		}
		for(int d=0; d<=k; ++d) {
			for(int i=k/2; i>=d+1; --i) {
				int opp=k-i+d;
				if(opp==i) continue;
				if(mod[i]>=mod[opp]) {
					sum-=mod[opp]*d;
					mod[i]-=mod[opp];
					mod[opp]=0;
				}
				else {
					sum-=mod[i]*d;
					mod[opp]-=mod[i];
					mod[i]=0;
				}
			}
		}
		for(int i=1; i<k; ++i) {
			if(i==0) continue;
			int sub=(i*2)%k, left=mod[i]%2;
			sum-=(mod[i]/2)*sub;
			if(left) sum-=i;
		}
		cout << sum/k << '\n';
	}
}