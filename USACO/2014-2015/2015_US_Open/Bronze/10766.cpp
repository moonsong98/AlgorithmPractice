#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<pair<int,int>> v(n);
	for(int i=0; i<n; ++i) 
		cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());
	
	long long ans=0;
	for(int i=0; i+1<n; ++i) {
		int l=i, r=i+1;
		bool possible=true;
		while(0<=l && r<=n-1) {
			int d=v[r].first-v[l].first;
			if(v[l].second < d) --l;
			if(v[r].second < d) ++r;
			int newD=v[r].first-v[l].first;
			if(d==newD) {
			 	possible=false;
				break;
			}
		}
		if(!possible) 
			ans+=v[i+1].first-v[i].first;
	}
	cout << ans << '\n';
}