#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<int> seq(n), inComing(n);
	vector<int> isCycle(n), edge(n);
	for(int i=0; i<n; ++i) cin >> seq[i];
	if(n==1) {
		cout << 1 << '\n';
		return 0;
	}
	sort(seq.begin(), seq.end());
	inComing[1]++; inComing[n-2]++;
	edge[0]=1; edge[n-1]=n-2;
	for(int i=1; i+1<n; ++i) {
		if(seq[i]-seq[i-1] <= seq[i+1]-seq[i]) {
			inComing[i-1]++;
			edge[i]=i-1;
		}
		else {
			inComing[i+1]++;
			edge[i]=i+1;
		} 
	}
	for(int i=0; i<n; ++i)
		if(edge[edge[i]]==i) isCycle[i]=isCycle[edge[i]]=true;
	
	int ans=0, cnt=0;
	for(int in: inComing) ans+=(in==2);
	for(int i=0; i<n; ++i) 
		if(isCycle[i]&&isCycle[edge[i]]&&inComing[i]==1&&inComing[edge[i]]==1) ++cnt;
	cout << ans+cnt/2 << '\n';
}