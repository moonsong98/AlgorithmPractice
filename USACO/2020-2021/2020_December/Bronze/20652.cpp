#include<iostream>
#include<vector>

using namespace std;

typedef struct {
	int x;
	int y;
} point;

typedef struct {
	char dir;
	point s;
	point e;
} cowInfo;

const int INF=987654321;
vector<int> minIndex;
int minMove;

void update(int i, int m) {
	if(m==minMove) minIndex.push_back(i);
	if(m<minMove) {
		minIndex.clear();
		minIndex.push_back(i);
		minMove=m;
	}
}

int main(void) {
	int n; cin >> n;
	vector<cowInfo> v;
	vector<int> ans(n, INF);
	for(int i=0; i<n; ++i) {
		int x, y; char dir;
		cin >> dir >> x >> y;
		v.push_back({dir, {x, y}, {x, y}});
	}
	
	vector<bool> finish(n, false);
	for(int t=0; t<n; ++t) {
		minIndex.clear(), minMove=INF;
		for(int i=0; i<n; ++i) {
			if(finish[i]) continue;
			for(int j=0; j<n; ++j) {
				if(i==j) continue;
				else if(finish[j]) {
					if(v[i].dir=='E'&&v[i].e.x<v[j].s.x&&v[j].s.y<=v[i].e.y&&v[i].e.y<=v[j].e.y) 
						update(i, v[j].e.x-v[i].e.x);
					else if(v[i].dir=='N'&&v[i].e.y<v[j].s.y&&v[j].s.x<=v[i].e.x&&v[i].e.x<=v[j].e.x) 
						update(i, v[j].e.y-v[i].e.y);
				}
				else {
					if(v[i].dir==v[j].dir) {
						if(v[i].dir=='E'&&v[i].e.y==v[j].e.y && v[i].e.x<v[j].e.x)
							update(i, v[j].e.x-v[i].e.x);
						else if(v[i].dir=='N'&&v[i].e.x==v[j].e.x && v[i].e.y<v[j].e.y) 
							update(i, v[j].e.y-v[i].e.y);
					}
					else if(v[i].dir!=v[j].dir) {
						if(v[i].dir=='E'&&v[i].e.x<=v[j].e.x&&v[j].s.y<=v[i].e.y) {
							if(v[j].e.x-v[i].e.x==v[i].e.y-v[j].e.y) continue;
							if(v[i].e.y>v[j].e.y && (v[i].e.y-v[j].e.y) < (v[j].e.x-v[i].e.x) || v[i].e.y<=v[j].e.y) 
								update(i, v[j].e.x-v[i].e.x);
						}
						else if(v[i].dir=='N'&&v[i].e.y<=v[j].e.y&&v[j].s.x<=v[i].e.x) {
							if(v[j].e.y-v[i].e.y==v[i].e.x-v[j].e.x) continue;
							if(v[i].e.x>=v[j].e.x && (v[j].e.y-v[i].e.y) > (v[i].e.x-v[j].e.x) || v[i].e.x<=v[j].e.x) 
								update(i, v[j].e.y-v[i].e.y);
						}
					}
				}
			}
		}
		
		if(minIndex.empty()) break;
		for(int i=0; i<n; ++i) {
			if(!finish[i]){
				if(v[i].dir=='E') v[i].e.x=min(v[i].e.x+minMove, int(1e9));
				else v[i].e.y=min(v[i].e.y+minMove, int(1e9));
			}
		}
		for(int i: minIndex) {
			finish[i]=true;
			if(v[i].dir=='E') ans[i]=v[i].e.x-v[i].s.x;
			else ans[i]=v[i].e.y-v[i].s.y;
		}
	}
	for(int i=0; i<n; ++i) {
		if(ans[i]==INF) cout << "Infinity" << '\n';
		else cout << ans[i] << '\n';
	}
}