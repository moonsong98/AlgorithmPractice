#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<int> log(n); for(int i=0; i<n; ++i) cin >> log[i];
	bool valid=true;
	if(log[0]>0) valid=false;
	log[0]=0;
	for(int i=1; i<n; ++i) {
		if(log[i]==-1) continue;
		for(int j=0; j<=log[i]; ++j) {
			if(i-j<0) break;
			if(log[i-j]!=-1&&log[i-j]!=log[i]-j) {
				valid=false;
				break;
			}
			log[i-j]=log[i]-j;
		}
		if(!valid) break;
	}
	if(!valid) cout << -1 << '\n';
	else {
		int numZeros=0, numOnes=0;
		for(int i=0; i<log.size(); ++i) {
			if(log[i]==0) ++numZeros;
			if(log[i]==-1)++numOnes;
		}
		cout << numZeros << ' ' << numOnes+numZeros << '\n';
	}
}