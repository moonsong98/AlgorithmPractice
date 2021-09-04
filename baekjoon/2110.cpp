#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> dist;

long long calc(long long m) {
	long long ret=0;
	long long sum=0;
	for(int i=0; i<dist.size(); ++i) {
		sum+=dist[i];
		if(sum>=m) {
			ret++;
			sum=0;
		}
	}
	return ret;
}

int main(void) {
	int n, c;
	cin >> n >> c;
	vector<long long> pos(n);
	for(int i=0; i<n; ++i) cin >> pos[i];
	sort(pos.begin(), pos.end());
	for(int i=0; i+1<n; ++i) dist.push_back(pos[i+1]-pos[i]);
	long long low=1, high=pos[n-1]-pos[0], ans;
	
	while(low<=high) {
		int mid=low+(high-low)/2;
		if(calc(mid)+1>=c) {
			ans=mid;
			low=mid+1;
		} else high=mid-1;
	}
	cout << ans << '\n';
}