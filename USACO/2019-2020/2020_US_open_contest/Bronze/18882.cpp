#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int main(void) {
	int N, T; cin >> N >> T;
	int x=0, y=987654321, z=-1;
	string str; cin >> str;
	vector<bool> isInfected(N+1);
	vector<bool> possibleP0(N+1, false);
	vector<pair<int,pair<int,int>>> interactions;
	for(int i=1; i<=N; ++i) isInfected[i]=str[i-1]=='1';
	for(int i=1; i<=T; ++i) {
		int t, a, b; cin >> t >> a >> b;
		interactions.push_back({t, {a, b}});
	}
	sort(interactions.begin(), interactions.end());
	for(int i=1; i<=N; ++i) {
		if(isInfected[i]==false) continue;
		for(int k=0; k<=251; ++k) {
			bool isKPossible=true;
			vector<int> checkInfected(N+1, false); checkInfected[i]=true;
			vector<int> numShakes(N+1, 0);
			for(int j=0; j<interactions.size(); ++j) {
				int u=interactions[j].second.first, v=interactions[j].second.second;
				if(checkInfected[u]) numShakes[u]++;
				if(checkInfected[v]) numShakes[v]++;
				if(checkInfected[u] && numShakes[u]<=k)checkInfected[v]=true;
				if(checkInfected[v] && numShakes[v]<=k)checkInfected[u]=true;
			}
			for(int i=1; i<=N; ++i) if(checkInfected[i]!=isInfected[i]) 
				isKPossible=false;
			if(isKPossible) {
				possibleP0[i]=true;
				y=min(y, k);
				z=max(z, k);
			}
		}
	}
	for(int i=1; i<=N; ++i) x+=possibleP0[i];
	cout << x << ' ' << y << ' ';
	if(z==251) cout << "Infinity" << '\n';
	else cout << z << '\n';
}