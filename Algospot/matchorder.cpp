#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> russian(n,0), korean(n,0);
		for(int i=0; i<n; ++i)
			cin>>russian[i];
		for(int i=0; i<n; ++i)
			cin>>korean[i];
		multiset<int> ratings(korean.begin(), korean.end());
		int ans=0;
		for(int rus=0; rus<n; ++rus){
			if(*ratings.rbegin() < russian[rus])
				ratings.erase(ratings.begin());
			else{
				ratings.erase(ratings.lower_bound(russian[rus]));
				++ans;
			}
		}
		cout<<ans<<'\n';
	}
}