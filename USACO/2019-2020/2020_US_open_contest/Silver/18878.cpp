#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int> M(m+1, -1);
	vector<int> leave(n+1, 0);
	for(int c=1; c<=n; ++c) {
		int f, s; cin >> f >> s;
		int before=M[f];
		M[f]=c;
		if(M[s]>before) continue;
		M[s]=before;
	}
	int total=0;
	for(int i=1; i<=m; ++i) 
		if(M[i]!=-1) {
			++total;
			leave[M[i]]++;
		}
	cout << total << '\n';
	for(int i=1; i<n; ++i){
		total-=leave[i];
		cout << total << '\n';
	}
}