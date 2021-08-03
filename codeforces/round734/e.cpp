#include<iostream>
#include<cstring>

using namespace std;
const int MAX_N=2*1000+11;

int dp[MAX_N][MAX_N];
int seq[MAX_N];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n, k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)
			cin>>seq[i];
		for(int i=0; i<n; ++i)
			for(int j=0; j<=i; ++j){
				dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
				dp[i+1][j+1]=max(
					(seq[i+1]==j+1?1:0)+dp[i][j], dp[i+1][j+1]
				);
			}
		
		int ans=-1;
		for(int i=n; i>=0; i--)
			if(dp[n][i]>=k){
				ans=n-i;
				break;
			}
		cout<<ans<<'\n';
	}
}