#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int N, M; cin >> N >> M;
	vector<vector<int>> r(N, vector<int>(2));
	vector<vector<int>> s(M, vector<int>(2));
	for(int i=0; i<N; ++i) cin >> r[i][0] >> r[i][1];
	for(int i=0; i<M; ++i) cin >> s[i][0] >> s[i][1];
	int a, b, i, j; a=b=i=j=0;
	int ans=0;
	while(a<100 && b<100) {
		int na=a+r[i][0];
		int nb=b+s[j][0];
		if(a<nb&&nb<=na || b<na&&na<=nb)
			if(s[j][1]>r[i][1]) ans=max(ans, s[j][1]-r[i][1]);
		if(na<=nb)
			a+=r[i++][0];
		else
			b+=s[j++][0];
	}
	cout << ans << '\n';
}