#include<iostream>
#include<cstring>

using namespace std;

int main(void) {
	int pos[26][2]; memset(pos, -1, sizeof(pos));
	for(int i=0; i<52; ++i) {
		char ch; cin >> ch;
		if(pos[ch-'A'][0]==-1) pos[ch-'A'][0]=i;
		else pos[ch-'A'][1]=i;
	}
	int ans=0;
	for(int i=0; i<26; ++i) for(int j=i+1; j<26; ++j) {
		if(pos[i][0] < pos[j][0] && pos[j][0] < pos[i][1] && pos[i][1] < pos[j][1]) ++ans;
		else if(pos[j][0] < pos[i][0] && pos[i][0] < pos[j][1] && pos[j][1] < pos[i][1]) ++ans;
	}
	cout << ans << '\n';
}