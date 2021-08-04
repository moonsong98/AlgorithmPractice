#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t; 
	while(t--){
		int n;
		cin>>n;
		vector<int> e(n,0), m(n,0);
		for(int i=0; i<n; ++i)
			cin>>m[i];
		for(int i=0; i<n; ++i)
			cin>>e[i];
		int ans=0, nextTime=0;
		vector<pair<int,int> > lunchBox;
		for(int i=0; i<n; ++i)
			lunchBox.push_back({e[i],m[i]});
		sort(lunchBox.begin(), lunchBox.end(), greater<pair<int,int>>());
		for(int i=0; i<n; ++i){
			ans=max(ans, nextTime+lunchBox[i].first+lunchBox[i].second);
			nextTime+=lunchBox[i].second;
		}
		cout<<ans<<'\n';
	}
}