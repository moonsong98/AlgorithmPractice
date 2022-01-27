#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n+1);
	vector<int> b(n); for(int i=1; i+1<=n; ++i) cin >> b[i];
	vector<int> c(n-1); for(int i=1; i+2<=n; ++i) c[i]=b[i+1]-b[i];
	vector<int> d(n+1,0); for(int i=3; i<=n; ++i) d[i]=d[i-2]+c[i-2];
	vector<int> taken(n+1, false);
	for(int i=1; i+1<=b[1]; ++i) {
		bool finish=true;
		a[1]=i;a[2]=b[1]-i;
		if(a[1]==a[2]||a[1]>n||a[2]>n) continue;
		taken.assign(n+1, false);
		taken[a[1]]=taken[a[2]]=true;
		for(int i=3; i<=n; ++i) {
			a[i]=d[i]+(i%2?a[1]:a[2]);
			if(a[i]<=0 || a[i]>n || taken[a[i]]) {
				finish=false;
				break;
			}
			else taken[a[i]]=true;
		}
		if(finish) {
			for(int i=1; i<=n; ++i) cout << a[i] << ' ';
			cout << '\n';
			break;
		}
	}
}