#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<bool> isUsed;

void solution(vector<int>& chosen) {
	if(chosen.size()==m) {
		for(int c: chosen) cout << c << ' ';
		cout << '\n';
	}
	for(int i=1; i<=n; ++i) {
		if(!isUsed[i]) {
			chosen.push_back(i);
			isUsed[i]=true;
			solution(chosen);
			chosen.pop_back();
			isUsed[i]=false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> chosen;
	isUsed=vector<bool>(n+1, false);
	solution(chosen);
}