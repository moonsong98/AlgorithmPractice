#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q; cin >> n >> q;
	set<int> notTakenX, notTakenY;
	vector<int> cntX(n+1, 0), cntY(n+1, 0);
	for(int i=1; i<=n; ++i){
		notTakenX.insert(i);
		notTakenY.insert(i);
	}
	for(int i=0; i<q; ++i) {
		int c; cin >> c;
		if(c<3) {
			int x, y; cin >> x >> y;
			if(c==1) {
				if(cntX[x]==0) notTakenX.erase(x);
				if(cntY[y]==0) notTakenY.erase(y);
				cntX[x]++;
				cntY[y]++;
			}
			else {
				cntX[x]--;
				if(cntX[x]==0) notTakenX.insert(x);
				cntY[y]--;
				if(cntY[y]==0) notTakenY.insert(y);
			}
		}
		else {
			int x1, y1, x2, y2, cnt=0;
			cin >> x1 >> y1 >> x2 >> y2;
			auto it=notTakenX.lower_bound(x1);
			if(it!=notTakenX.end()&&*it<=x2) ++cnt;
			it=notTakenY.lower_bound(y1);
			if(it!=notTakenY.end()&&*it<=y2) ++cnt;
			cout << (cnt==2?"NO":"YES") << '\n';
		}
	}
}