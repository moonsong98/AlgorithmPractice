#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<int> a1(n), a2(n);
	vector<int> d1(2*n), d2(n);
	bool ans=true;
	for(int i=0; i<n; ++i) cin >> a1[i];
	for(int i=0; i<n; ++i) cin >> a2[i];
	sort(all(a1));
	sort(all(a2));
	for(int i=0; i+1<n; ++i) d1[i+n]=d1[i]=a1[i+1]-a1[i];
	for(int i=0; i+1<n; ++i) d2[i]=a2[i+1]-a2[i];
	d1[2*n-1]=d1[n-1]=a1[0]+360000-a1.back();
	d2[n-1]=a2[0]+360000-a2.back();
	
	vector<int>fail(n, 0);
	for(int i=1,j=0; i<n; ++i) {
		while(j>0&&d2[i]!=d2[j]) j=fail[j-1];
		if(d2[i]==d2[j]) fail[i]=++j;
	}
	for(int i=0, j=0; i<n*2; ++i) {
		while(j>0&&d1[i]!=d2[j]) j=fail[j-1];
		if(d1[i]==d2[j]) {
			++j;
			if(j==n) {
				cout << "possible" << '\n';
				return 0;
			}
		}
	}
	cout << "impossible" << '\n';
}