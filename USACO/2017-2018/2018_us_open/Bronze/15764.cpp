#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, m, k; cin >> n >> m >> k;
	vector<int> pos(n+1,-1);
	vector<int> seq(n+1,-1);
	vector<int> hierarchy(m);
	
	int posOne=-1;
	for(int i=0; i<m; ++i) {
		cin >> hierarchy[i];
		if(hierarchy[i]==1) posOne=i;
	}
	for(int i=0; i<k; ++i) {
		int a, b; cin >> a >> b;
		seq[b]=a;
		pos[a]=b;
	}
	for(int i=0; i<posOne; ++i) {
		int u=hierarchy[i];
		if(pos[u]!=-1) continue;
		for(int j=(i==0?1:pos[hierarchy[i-1]]+1); j<=n; ++j)
			if(seq[j]==-1) {
				pos[u]=j;
				seq[j]=u;
				break;
			}
	}
	if(posOne>0) {
		for(int i=pos[hierarchy[posOne-1]]; i<=n; ++i) if(seq[i]==-1) {
			cout << i << '\n';
			return 0;
		}
	}
	for(int i=m-1; i>posOne; --i) {
		int u=hierarchy[i];
		if(pos[u]!=-1) continue;
		for(int j=(i==m-1?n:pos[hierarchy[i+1]]-1); j>=1; --j) 
			if(seq[j]==-1) {
				pos[u]=j;
				seq[j]=u;
				break;
			}
	}
	
	for(int i=1; i<=n; ++i) if(seq[i]==-1) {
		cout << i << '\n';
		return 0;
	}
}