#include<iostream>
#include<string>

using namespace std;

const int MAX=100;

int shuffle[MAX+1], seq[MAX+1], tmp[MAX+1];
string names[MAX+1];
string ans[MAX+1];

int main(void) {
	int n; cin >> n;
	for(int i=1; i<=n; ++i) cin >> shuffle[i];
	for(int i=1; i<=n; ++i) cin >> names[i];
	for(int i=1; i<=n; ++i) seq[i]=i;
	
	for(int i=0; i<3; ++i) {
		for(int i=1; i<=n; ++i) tmp[shuffle[i]]=seq[i];
		for(int i=1; i<=n; ++i) seq[i]=tmp[i];
	}
	
	for(int i=1; i<=n; ++i) ans[seq[i]]=names[i];
	for(int i=1; i<=n; ++i) cout << ans[i] << '\n';
}