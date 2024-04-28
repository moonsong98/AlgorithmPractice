#include<iostream>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const long long INF=99999999999;

int n;
vector<pair<int,int>> matrices;
long long cache[511][511];

long long dp(int s, int e){
	long long& ret=cache[s][e];
	if(ret!=-1) return ret;
	
	if(s==e) return ret=0;
	if(s+1==e) return ret=matrices[s].first*matrices[s].second*matrices[e].second;
	
	ret=INF;
	for(int l=s; l<e; ++l)
		ret=min(ret, (long long)dp(s,l)+dp(l+1,e)+matrices[s].first*matrices[l].second*matrices[e].second);
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(cache, -1, sizeof(cache));
	
	cin>>n;
	for(int i=0; i<n; ++i){
		int s, e;
		cin>>s>>e;
		matrices.push_back({s,e});
	}
	
	cout<<dp(0, n-1)<<'\n';
}