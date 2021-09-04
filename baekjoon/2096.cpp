#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int b[3], dp[3]={0,}, dp2[3]={0,};
	vector<int>dir[3]={{0,1},{-1, 0, 1},{-1,0}};
	for(int i=0; i<3; ++i) {
		cin >> b[i];
		dp[i]=dp2[i]=b[i];
	}
		// cout << '\n';
		// for(int c: dp) cout << c << ' ' ;
		// cout << '\n';
	for(int i=1; i<n; ++i) {
		int temp[3]={dp[0],dp[1],dp[2]}, temp2[3]={dp2[0], dp2[1], dp2[2]};
		for(int j=0; j<3; ++j) cin >> b[j];
		for(int j=0; j<3; ++j)  {
			int cand=0, cand2=987654321;
			for(int k=0; k<dir[j].size(); ++k) {
				int d=dir[j][k];
				cand=max(b[j]+dp[j+d], cand);
				cand2=min(b[j]+dp2[j+d], cand2);
			}
			temp[j]=cand;
			temp2[j]=cand2;
		}
		for(int j=0; j<3; ++j) {
			dp[j]=temp[j];
			dp2[j]=temp2[j];
		}
		// cout << '\n';
		// for(int c: dp) cout << c << ' ' ;
		// cout << '\n';
	}
	int ans=-1, ans2=98765421;
	for(int i=0; i<3; ++i) ans=max(dp[i], ans);
	for(int i=0; i<3; ++i) ans2=min(dp2[i], ans2);
	cout << ans << ' ' << ans2 << '\n';
}