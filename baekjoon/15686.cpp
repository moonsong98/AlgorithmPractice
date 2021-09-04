#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>

using namespace std;

int n, m;
int ans=987654321;
vector<pair<int,int>> houses;
vector<pair<int,int>> stores;

void calc(vector<int>& chosen) {
	if(chosen.size()==m) {
		int sum=0;
		for(int i=0; i<houses.size(); ++i) {
			int cand=987654321;
			for(int j=0; j<m; ++j) {
				int dist=abs(houses[i].first-stores[chosen[j]].first)+abs(houses[i].second-stores[chosen[j]].second);
				cand=min(cand, dist);
			}
			sum+=cand;
		}
		ans=min(ans, sum);
		return;
	}
	int l=chosen.size() >= 1 ? chosen.back()+1 : 0;
	if(l==stores.size()) return;
	for(; l<stores.size(); ++l){
		chosen.push_back(l);
		calc(chosen);
		chosen.pop_back();
	}
}

int main(void) {
	cin >> n >> m;
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
		int a;
		cin >> a;
		if(a==1) houses.push_back({i,j});
		else if(a==2) stores.push_back({i,j});
	}
	vector<int> chosen;
	calc(chosen);
	cout << ans << '\n';
}