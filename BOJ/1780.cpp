#include<iostream>
#include<vector>

using namespace std;

int o,z,m;
vector<vector<int>> b;

void solve(int y, int x, int size) {
	if(size==1) {
		int f=b[y][x];
		if(f==-1) ++m;
		if(f==0) ++z;
		if(f==1) ++o;
		return;
	}
	int f=b[y][x];
	for(int i=y; i<size+y; ++i) for(int j=x; j<size+x; ++j) {
		if(b[i][j] != f) {
			int newSize=size/3;
			for(int k=0; k<3; ++k) for(int l=0; l<3; ++l) solve(y+newSize*k, x+newSize*l, newSize);
			return;
		}
	}
	if(f==-1) ++m;
	if(f==0) ++z;
	if(f==1) ++o;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	b=vector<vector<int>>(n, vector<int> (n));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> b[i][j];
	solve(0,0,n);
	cout << m << '\n' << z << '\n' << o << '\n';
}