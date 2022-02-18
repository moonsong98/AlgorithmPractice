#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int N, M; cin >> N >> M;
	vector<vector<char>> b(N, vector<char>(M));
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin >> b[i][j];
	int cnt=0;
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) {
		if(b[i][j]=='#') continue;
		bool isHint=false;
		if((j==0 || b[i][j-1]=='#')&&j+2<M&&b[i][j+1]==b[i][j+2]&&b[i][j+1]=='.') isHint=true;
		else if((i==0 || b[i-1][j]=='#')&&i+2<N&&b[i+1][j]==b[i+2][j]&&b[i+1][j]=='.') isHint=true;
		if(isHint) {
			++cnt;
			b[i][j]='!';
		}
	}
	cout << cnt << '\n';
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) if(b[i][j]=='!') cout << i+1 << ' ' << j+1 << '\n';
}