#include<iostream>
#include<string>

using namespace std;

int dp[1000011], len;
string w;

int main(void) {
	cin >> len;
	cin >> w;
	for(int i=len-1; i>=0; --i) {
		dp[i]=dp[i+1];
		if(w[i] == 'p' && i+4 <=len && w.substr(i, 4) == "pPAp")
			dp[i]=max(dp[i], dp[i+4]+1);
	}
	cout << dp[0] << '\n';
}