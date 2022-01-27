#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<vector<int>> nextTo(8);
	vector<string> names={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
	sort(names.begin(), names.end());
	auto getNameIndex = [=](string s) -> int{for(int i=0; i<8; ++i) if(names[i]==s) return i;};
	for(int i=0; i<N; ++i) {
		string A, B, C;
		cin >> A >> C >> C >> C >> C >> B;
		nextTo[getNameIndex(A)].push_back(getNameIndex(B));
		nextTo[getNameIndex(B)].push_back(getNameIndex(A));
		cout << getNameIndex(A) << ' ' << getNameIndex(B) << '\n';
	}
	vector<int> seq;
	vector<bool> taken(N, false);
	for(int i=0; i<8; ++i) {
		if(taken[i]||nextTo[i].size()==2 && !taken[nextTo[i][0]] && !taken[nextTo[i][1]]) continue;
		taken[i]=true;
		if(nextTo[i].size()==0) seq.push_back(i);
		else {
			int a=i;
			while(a!=-1) {
				seq.push_back(a);
				taken[a]=true;
				int b=-1;
				for(int c: nextTo[a]) if(!taken[c]) b=c;
				a=b;
			}
		}
	}
	for(int i=0; i<8; ++i) cout << names[seq[i]] << '\n';
}
	