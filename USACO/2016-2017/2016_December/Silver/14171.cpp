#include<bits/stdc++.h>
using namespace std;

long long cnt[676][676];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	for(int i=0; i<N; ++i) {
		string str[2];
		cin >> str[0] >> str[1];
		int u=(str[0][0]-'A')*26+str[0][1]-'A';
		int v=(str[1][0]-'A')*26+str[1][1]-'A';
		cnt[u][v]++;
	}
	long long ans=0;
	for(int i=0; i<26*26; ++i) for(int j=0; j<26*26; ++j)
		if(i!=j&&cnt[i][j])
		 ans+=cnt[i][j]*cnt[j][i];
	cout << ans/2 << '\n';
}