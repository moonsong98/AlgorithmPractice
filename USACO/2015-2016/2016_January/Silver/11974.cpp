#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; 
	cin >> N;
	int sum=0;
	vector<vector<int>> pos(7,vector<int>(2,-1));
	for(int i=1; i<=N; ++i) {
		int a; cin >> a;
		sum=sum+a;
		if(sum>=7) sum%=7;
		if(sum==0||pos[sum][0]>-1) pos[sum][1]=i;
		else pos[sum][0]=pos[sum][1]=i;
	}
	int ans=pos[0][1];
	for(int i=1; i<7; ++i) ans=max(ans, pos[i][1]-pos[i][0]);
	cout << ans << '\n';
}