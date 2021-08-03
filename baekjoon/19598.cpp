#include<iostream>
#include<utility>
#include<queue>

using namespace std;

const int MAX_N=1000*1000+11;

int beginTime[MAX_N], endTime[MAX_N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> notStarted;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> onGoing;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	int ans=-1;
	for(int i=0; i<n; ++i) {
		cin>>beginTime[i]>>endTime[i];
		notStarted.push({beginTime[i],endTime[i]});
	}
	
	while(!notStarted.empty()) {
		int end=notStarted.top().second, begin=notStarted.top().first;
		notStarted.pop();
		while(!onGoing.empty() && onGoing.top().first<=begin){
			onGoing.pop();
		}
		onGoing.push({end,begin});
		int size=onGoing.size();
		ans=max(ans, size);
	}
	cout << ans << '\n';
}