#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
	int l, r;
} line;

bool operator < (line a, line b) {
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<line> lines;
	for(int i=0; i<n; ++i) {
		int u, v; cin >> u >> v;
		lines.push_back({u, v});
	}
	sort(lines.begin(), lines.end());
	int l=lines[0].l, r=lines[0].r;
	int ans=0;
	for(line e: lines) {
		if(r<e.r) {
			if(e.l<=r) r=e.r;
			else {
				ans+=r-l;
				l=e.l, r=e.r;
			}
		}
	}
	cout << ans + r - l << '\n';
}