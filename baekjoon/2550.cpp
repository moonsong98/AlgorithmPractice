#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<int> switchNum(n), switchPos(n+1), lightNum(n), seq(n); 
	for(int i=0; i<n; ++i) {
		cin >> switchNum[i];
		switchPos[switchNum[i]]=i;
	}
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		seq[switchPos[a]]=i;
		lightNum[i]=a;
	}
	vector<int> dp, dpPos(n);
	vector<int>::iterator it;
	for(int i=0; i<n; ++i) {
		if(dp.empty() || dp.back() < seq[i]) {
			dp.push_back(seq[i]);
			dpPos[i]=dp.size()-1;
		}
		else {
			it=lower_bound(dp.begin(), dp.end(), seq[i]);
			*it=seq[i];
			dpPos[i]=it-dp.begin();
		}
	}
	vector<int> ans(dp.size());
	for(int i=n-1; i>=0; --i) {
		int p=dpPos[i];
		if(p == dp.size()-1 || seq[i] < ans[p+1]) ans[p]=seq[i];
	}
	for(int i=0; i<ans.size(); ++i) ans[i]=lightNum[ans[i]];
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int n: ans) cout << n << ' ';
	cout << '\n';
}