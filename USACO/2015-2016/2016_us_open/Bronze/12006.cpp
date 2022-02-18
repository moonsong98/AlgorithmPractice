#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N, K;

bool shift(vector<string> &a, int v, int h) {
	vector<string> b(N, string(N,'.'));
	for(int i=0; i<N; ++i) {
		for(int j=0; j<N; ++j) {
			if(a[i][j]=='#') {
				if(0 > i+v || i+v > N-1 || 0 > j+h || j+h > N-1)
					return false;
				b[i+v][j+h]='#';
			}
		}
	}
	a=b;
	return true;
}

vector<string> attach(vector<string> &a, vector<string> &b) {
	vector<string> res(N, string(N, '.'));
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
		char ca=a[i][j], cb=b[i][j];
		if(ca=='#'&&cb=='#') return res;
		else if(ca=='#'||cb=='#') res[i][j]='#';
	}
	return res;
}

int main(void) {
	cin >> N >> K;
	vector<string> w(N);
	for(int i=0; i<N; ++i) cin >> w[i];
	vector<vector<string>> p(K,vector<string>(N)); 
	for(int k=0; k<K; ++k) for(int i=0; i<N; ++i) cin >> p[k][i];
	for(int i=0; i<K; ++i) {
		for(int j=i+1; j<K; ++j) {
			for(int a=-N; a<N; ++a) {
				for(int b=-N; b<N; ++b) {
					for(int c=-N; c<N; ++c) {
						for(int d=-N; d<N; ++d) {
							vector<string> p1=p[i], p2=p[j];
							if(shift(p1, a, b)&&shift(p2, c, d)) {
								vector<string> attached=attach(p1, p2);
								if(attached==w) {
									cout << i+1 << ' ' << j+1 << '\n';
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	
}