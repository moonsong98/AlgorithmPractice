#include<iostream>
#include<cstring>

using namespace std;

int main(void) {
	int N; cin >> N;
	int state[11]; memset(state, -1, sizeof(state));
	int cnt[11]; memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<N; ++i) {
		int a, b; cin >> a >> b;
		if(state[a]==-1) state[a]=b;
		else if(state[a]!=b) {
			state[a]=b;
			cnt[a]++;
		}
	}
	int ans=0;
	for(int c: cnt) ans+=c;
	cout << ans << '\n';
}