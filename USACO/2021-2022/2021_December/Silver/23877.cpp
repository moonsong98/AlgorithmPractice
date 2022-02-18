#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<ll> a(M+1, 0), b(M+1, 0);
	vector<ll> up(2*M+1, 0), down(2*M+1, 0);
	for(int i=0; i<N; ++i) {
		int p, q;
		cin >> p >> q;
		a[p]++;
		b[q]++;
	}
	for(int i=0; i<=M; ++i) {
		for(int j=0; j<=M; ++j) {
			up[i+j]+=a[i]*a[j];
			down[i+j]+=b[i]*b[j];
		}
	}
	long long cnt=0;
	for(int i=0; i<=2*M; ++i) {
		cnt+=up[i];
		cout << cnt << '\n';
		cnt-=down[i];
	}
}