#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	const int INF=987654321;
	int len; cin >> len;
	vector<int> seq(len); for(int i=0; i<len; ++i) cin>>seq[i];
	vector<int> dp(1, INF);
	for(int i=0; i<len; ++i) {
		if(seq[i] > dp.back()) dp.push_back(seq[i]);
		else *lower_bound(dp.begin(), dp.end(), seq[i])=seq[i];
	}
	cout << len-dp.size() << '\n';
}