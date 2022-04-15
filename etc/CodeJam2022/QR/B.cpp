#include<bits/stdc++.h>
using namespace std;

int nums[3][4];
int mins[4];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	for(int i=1; i<=t; ++i){
		memset(nums,0,sizeof(nums));
		memset(mins,0,sizeof(mins));
		cout << "CASE #" << i << ": ";
		int left=0;
		for(int j=0; j<3; ++j) for(int k=0; k<4; ++k) cin >> nums[j][k];
		for(int j=0; j<4; ++j) {
			mins[j]=min({nums[0][j],nums[1][j],nums[2][j]});
			left+=mins[j];
		}
		if(left<1e6) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		left=1e6;
		for(int j=0; j<4; ++j) {
			if(left<mins[j]) {
				cout << left << ' ';
				left=0;
			}
			else {
				cout << mins[j] << ' ';
				left-=mins[j];
			}
		}
		cout << '\n';
	}
}