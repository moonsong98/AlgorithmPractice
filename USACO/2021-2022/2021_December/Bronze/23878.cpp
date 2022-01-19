#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, cnt=1; cin >> n;
	long long ans=0;
	char ch, cur; cin >> ch; cur=ch;
	vector<int> seq;
	for(int i=0; i+1<n; ++i) {
		cin >> ch; 
		if(cur!=ch) {
			seq.push_back(cnt);
			cur=ch;
			cnt=0;
		}
		++cnt;
	}
	seq.push_back(cnt);
	
	if(seq.size()==1) {
		cout << "0" << '\n';
		return 0;
	}
	
	for(int i=0; i+1<seq.size(); ++i) {
		long long x=seq[i], y=seq[i+1], z=-1;
		if(i+2<seq.size()) z=seq[i+2];
		ans+=(x+y-2);
		if(y==1 && z!=-1) ans+=(x*z);
	}
	cout << ans << '\n';
}