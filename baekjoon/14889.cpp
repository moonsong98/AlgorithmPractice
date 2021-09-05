#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int>> s;
vector<bool> chosen;
int n, numChosen;

int ans=987654321;

void solve(int pos) {
	if(numChosen==n/2) {
		vector<int> team1;
		vector<int> team2;
		int s1=0, s2=0;
		for(int i=0; i<n; ++i) {
			if(chosen[i]) team1.push_back(i);
			else team2.push_back(i);
		}
		for(int i=0; i<n/2; ++i) for(int j=0; j<n/2; ++j)
			if(i!=j) s1+=s[team1[i]][team1[j]];
		for(int i=0; i<n/2; ++i) for(int j=0; j<n/2; ++j)
			if(i!=j) s2+=s[team2[i]][team2[j]];
		ans=min(ans, abs(s1-s2));
		return;
	}
	for(int i=pos; i<n; ++i) {
		chosen[pos]=true;
		numChosen++;
		solve(i+1);
		chosen[pos]=false;
		numChosen--;
	}
}

int main(void) {
	cin >> n;
	chosen=vector<bool>(n, false);
	s=vector<vector<int>>(n, vector<int>(n));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> s[i][j];
	solve(0);
	cout << ans << '\n';
}