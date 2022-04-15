#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;

bool found[101][101]={false,};

int main(void) {
	int X,Y,K,M;
	cin >> X >> Y >> K >> M;
	queue<pair<pii,int>>q;
	found[0][0]=true;
	q.push({{0,0},0});
	int ans=INT_MAX;
	while(!q.empty()) {
		int y=q.front().fi.fi, x=q.front().fi.se, n=q.front().se;
		q.pop();
		ans=min(ans, abs(M-y-x));
		if(n==K) continue;
		int ny, nx, nn=n+1, diff;
		ny=Y; nx=x;
		if(!found[ny][nx]) {
			q.push({{ny, nx}, nn});
			found[ny][nx]=true;
		}
		ny=y, nx=X;
		if(!found[ny][nx]) {
			q.push({{ny, nx}, nn});
			found[ny][nx]=true;
		}
		ny=0; nx=x;
		if(!found[ny][nx]) {
			q.push({{ny, nx}, nn});
			found[ny][nx]=true;
		}
		ny=y; nx=0;
		if(!found[ny][nx]) {
			q.push({{ny, nx}, nn});
			found[ny][nx]=true;
		}
		diff=min(Y-y, x);
		ny=y+diff, nx=x-diff;
		if(!found[ny][nx]) {
			q.push({{ny, nx}, nn});
			found[ny][nx]=true;
		}
		diff=min(y, X-x);
		ny=y-diff, nx=x+diff;
		if(!found[ny][nx]) {
			q.push({{ny, nx}, nn});
			found[ny][nx]=true;
		}
	}
	cout << ans << '\n';
}