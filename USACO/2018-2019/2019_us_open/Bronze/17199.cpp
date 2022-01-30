#include<iostream>

using namespace std;

const int MAX_NODE=100;

int inComing[MAX_NODE+1];
int outGoing[MAX_NODE+1];

int main(void) {
	int N; cin >> N;
	
	for(int i=0; i<N-1; ++i) {
		int u, v;
		cin >> u >> v;
		outGoing[u]++;
		inComing[u]++;
	}
	
	int ans=-1;
	for(int i=1; i<=N; ++i) {
		if(outGoing[i]==0 && ans!=-1) {
			ans=-1;
			break;
		}
		if(outGoing[i]==0 && inComing[i]>0) ans=i;
	}
	cout << ans << '\n';
}
