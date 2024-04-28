#include<iostream>
#include<vector>
#include<algorithm>

#define sz(x) (int)x.size()

using namespace std;

void solve() {
	int L, K, C;
	cin >> L >> K >> C;
	vector<int> cutPoints;
	cutPoints.push_back(0);
	for(int i=0; i<K; ++i) {
		int a; cin >> a;
		cutPoints.push_back(a);
	} 
	cutPoints.push_back(L);
	sort(cutPoints.begin(), cutPoints.end());
	cutPoints.erase(unique(cutPoints.begin(), cutPoints.end()), cutPoints.end());
	vector<int> partLen;
	for(int i=0; i+1<sz(cutPoints); ++i) partLen.push_back(cutPoints[i+1]-cutPoints[i]);
	
	int l=1, r=L;
	int ans[2];
	while(l<=r) {
		int mid=l+(r-l)/2;
		int left=C+1;
		int curLen=0;
		int minIndex=-1;
		bool valid=true;
		for(int i=sz(partLen)-1; i>=0; --i) {
			if(partLen[i]>mid) {
				valid=false;
				break;
			}
			if(curLen+partLen[i]>mid) {
				--left;
				curLen=partLen[i];
			}
			else curLen+=partLen[i];
			if(left==1) {
				if(cutPoints[i+1]<=mid) minIndex=i+1;
				else valid=false;
				break;
			}
		}
		if(valid&&left>1) minIndex=1;
		if(valid) {
			ans[0]=mid;
			ans[1]=cutPoints[minIndex];
			r=mid-1;
		}
		else l=mid+1;
	}
	cout << ans[0] << ' ' << ans[1] << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}