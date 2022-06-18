#include<bits/stdc++.h>
using namespace std;

const int INF=1e7;
int dp[10013][4],v1[10013], v2[10012];
int N, W;

void calc() {
	for(int i=1; i<N; ++i) {
		dp[i][0]=dp[i-1][3];
		dp[i][1]=dp[i-1][3]+1;
		if(v1[i-1]+v1[i]<=W) dp[i][1]=min(dp[i][1], dp[i-1][2]+1);
		dp[i][2]=dp[i-1][3]+1;
		if(v2[i-1]+v2[i]<=W) dp[i][2]=min(dp[i][2], dp[i-1][1]+1);
		dp[i][3]=dp[i-1][3]+(v1[i]+v2[i]<=W?1:2);
		if(v1[i-1]+v1[i]<=W) {
			dp[i][3]=min(dp[i][3], dp[i-1][2]+2);
			if(v2[i-1]+v2[i]<=W)
				dp[i][3]=min(dp[i][3], dp[i-1][0]+2);
		}
		if(v2[i-1]+v2[i]<=W)
			dp[i][3]=min(dp[i][3], dp[i-1][1]+2);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		cin >> N >> W;
		for(int i=0; i<N; ++i) cin >> v1[i];
		for(int i=0; i<N; ++i) cin >> v2[i];
		if(N==1) {
			cout << (v1[0]+v2[0]<=W?1:2) << '\n';
			continue;
		}
		int ans=INT_MAX;
		dp[0][0]=0; dp[0][1]=dp[0][2]=1; dp[0][3]=v1[0]+v2[0]<=W?1:2;
		calc();
		ans=min(ans, dp[N-1][3]);
		if(v1[0]+v1[N-1]<=W) {
			dp[0][0]=0; dp[0][1]=dp[0][2]=1; dp[0][3]=2;
			int tmp=v1[0]; v1[0]=INF;
			calc();
			ans=min(ans, dp[N-1][2]);
			v1[0]=tmp;
		}
		if(v2[0]+v2[N-1]<=W) {
			dp[0][0]=0; dp[0][1]=dp[0][2]=1; dp[0][3]=2;
			int tmp=v2[0]; v2[0]=INF;
			calc();
			ans=min(ans, dp[N-1][1]);
			v2[0]=tmp;
		}
		if(v1[0]+v1[N-1]<=W && v2[0]+v2[N-1]<=W) {
			dp[0][0]=0; dp[0][1]=dp[0][2]=1; dp[0][3]=2;
			int tmp1=v1[0]; v1[0]=INF;
			int tmp2=v2[0]; v2[0]=INF;
			calc();
			ans=min(ans, dp[N-2][3]);
			v1[0]=tmp1, v2[0]=tmp2;
		}
		cout << ans << '\n';
	}
}