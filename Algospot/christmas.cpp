#include<iostream>
#include<vector>

using namespace std;

const long long MOD=20091101ll;

void solve() {
	int N, K;
	long long ans1=0, ans2;
	cin >> N >> K;
	vector<long long> pSum(N+1, 0);
	vector<long long> cnt(K, 0);
	vector<int> prev(N+1, -1);
	vector<int> prevTmp(K, -1);
	vector<int> dp(N+1, 0);
	for(int i=0; i<=N; ++i) {
		if(i>0) {
    		cin >> pSum[i];
	    	pSum[i]=(pSum[i]+pSum[i-1])%K;		    
		}
		cnt[pSum[i]]++;
		prev[i]=prevTmp[pSum[i]];
		prevTmp[pSum[i]]=i;
	}
	for(int i=0; i<K; ++i)
		if(cnt[i]>1)
			ans1+=cnt[i]*(cnt[i]-1)/2;
	ans1%=MOD;
	for(int i=1; i<=N; ++i) {
		dp[i]=dp[i-1];
		if(prev[i]!=-1) dp[i]=max(dp[i], dp[prev[i]]+1);
	}
	ans2=dp[N];
	cout << ans1 << ' ' << ans2 << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--)
		solve();
}