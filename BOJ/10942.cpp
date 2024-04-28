#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> seq;
int cache[2011][2011];

int pal(int s, int e) {
	int& ret=cache[s][e];
	if(ret!=-1) return ret;
	
	ret=seq[e]==seq[s];
	return ret=ret&&(e-s>1?pal(s+1, e-1):1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(cache, -1, sizeof(cache));
	
	int n;
	cin>>n;
	
	seq=vector<int>(n+1,0);	
	for(int i=1; i<=n; ++i) cin>>seq[i];
	
	for(int i=1; i<=n; ++i)
		for(int j=n; j>0; --j){
			if(j<i) break;
			if(cache[i][j]==-1) pal(i,j);
		}
	
	int t;
	cin>>t;
	for(int i=0; i<t; ++i){
		int s, e;
		cin>>s>>e;
		cout<<cache[s][e]<<'\n';
	}
}