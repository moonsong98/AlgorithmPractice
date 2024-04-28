#include<iostream>

using namespace std;

int main(void) {
	int seq[41]; seq[1]=1; seq[2]=2;
	for(int i=3; i<=40; ++i) seq[i]=seq[i-1]+seq[i-2];
	int n, m; cin >> n >> m;
	int l=1, r, ans=1;
	for(int i=0; i<m; ++i) {
		cin >> r;
		if(l<r) ans*=seq[r-l];
		l=r+1;
	}
	r=n;
	if(l<r) ans*=seq[r-l+1];
	cout<<ans<< '\n';
}