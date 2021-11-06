#include<iostream>

using namespace std;

int boxes[1001], dp[1001];

int main(void) {
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) cin >> boxes[i];
	dp[0]=1;
	for(int i=1; i<=n; ++i) {
		dp[i]=1;
		for(int j=0; j<i; ++j) 
			if(i==n || boxes[i] > boxes[j]) 
				dp[i]=max(dp[i], dp[j]+1);
	}
	cout << dp[n]-1 << '\n';
}