#include<iostream>

using namespace std;

const int MOD=1e9;
const int ALLUSED=(1<<10)-1;
int dp[100][10][1<<10] = {0,};
int add(const int a, const int b) {
	return ((a%MOD) + (b%MOD)) % MOD;
}

int main(void) {
	int len, ans=0; cin >> len;
	for(int i=1; i<=9; ++i) dp[0][i][1<<i]=1;
	for(int i=1; i<len; ++i) for(int j=0; j<=9; ++j) for(int k=0; k<=ALLUSED; ++k){
		if(j>0) dp[i][j][k|(1<<j)] = add(dp[i][j][k|(1<<j)], dp[i-1][j-1][k]);
		if(j<9) dp[i][j][k|(1<<j)] = add(dp[i][j][k|(1<<j)], dp[i-1][j+1][k]);
	}
	for(int i=0; i<=9; ++i) ans=add(ans, dp[len-1][i][ALLUSED]);
	cout << ans <<'\n';
}