#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int INF=987654321;

int n;
vector<int> d;
long long ans;

void normalize(int, int);

void getSubsequence(int l, int r) {
	int nl, nr;
	for(int i=l; i<=r; ++i) {
		if(d[i]>0) {
			int nl=i; nr=i;
			for(++i;i<=r; ++i) {
				if(d[i]>0) nr=i;
				else break;
			}
			normalize(nl, nr);
			--i;
		}
		if(d[i]<0) {
			nl=i; nr=i;
			for(++i;i<=r; ++i) {
				if(d[i]<0) nr=i;
				else break;
			}
			normalize(nl, nr);
			--i;
		}
	}
}

void normalize(int l, int r) {
	int min=INF;
	for(int i=l; i<=r; ++i)
		if(abs(d[i])<abs(min)) min=d[i];
	for(int i=l; i<=r; ++i) d[i]-=min;
	ans+=abs(min);
	getSubsequence(l, r);
}

int main(void) {
	cin >> n; d=vector<int>(n);
	for(int i=0; i<n; ++i) cin >> d[i];
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		d[i]=a-d[i];
	}
	getSubsequence(0, n-1);
	cout << ans << '\n';
}