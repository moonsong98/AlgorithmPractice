#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void) {
	string str[3]; for(int i=0; i<3; ++i) cin >> str[i];
	int len[3]; for(int i=0; i<3; ++i) len[i]=str[i].size();
	vector<vector<vector<int>>> dp(len[0]+1, vector<vector<int>>(len[1]+1, vector<int>(len[2]+1, 0)));
	for(int i=1; i<=len[0]; ++i) 
		for(int j=1; j<=len[1]; ++j) 
			for(int k=1; k<=len[2]; ++k) {
				if(str[0][i-1]==str[1][j-1] && str[1][j-1]==str[2][k-1]) dp[i][j][k] = dp[i-1][j-1][k-1]+1;
				else dp[i][j][k]=max(dp[i][j][k-1],max(dp[i][j-1][k], dp[i-1][j][k]));
			}
	cout << dp[len[0]][len[1]][len[2]] << '\n';
}