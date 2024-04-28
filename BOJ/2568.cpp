#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b) {
	return a.second < b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pair<int,int>> seq;
	vector<pair<int,int>> dp;
	vector<int> pos(n);
	for(int i=0; i<n; ++i) {
		int a, b; cin >> a >> b;
		seq.push_back({a,b});
	}
	sort(seq.begin(), seq.end());
	for(int i=0; i<n; ++i) {
		if(dp.empty() || dp.back().second < seq[i].second) {
			dp.push_back(seq[i]);
			pos[i]=dp.size()-1;
		}
		else {
			vector<pair<int,int>>::iterator it = lower_bound(dp.begin(), dp.end(), seq[i], comp);
			*it=seq[i];
			pos[i]=it-dp.begin();
		}
	}
	cout << n-dp.size() << '\n';
	vector<pair<int,int>> stay(dp.size());
	for(int i=n-1; i>=0; --i) {
		int p=pos[i];
		if(p==dp.size()-1 || seq[i].second < stay[p+1].second) stay[p]=seq[i];
	}
	vector<pair<int,int>>::iterator it=stay.begin();
	vector<int> ans;
	for(int i=0; i<n; ++i) {
		if(it==stay.end() || seq[i].first != it->first) ans.push_back(seq[i].first);
		else ++it;
	}
	for(int n: ans) cout << n << '\n';
}