#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string str1, str2;
		cin >> str1 >> str2;
		vector<int> posA1, posA2, posC1, posC2;
		for(int i=0; i<n; ++i) {
			if(str1[i]=='a') posA1.push_back(i);
			else if(str1[i]=='c') posC1.push_back(i);
		}
		for(int i=0; i<n; ++i) {
			if(str2[i]=='a') posA2.push_back(i);
			else if(str2[i]=='c') posC2.push_back(i);
		}
		if(sz(posA1)!=sz(posA2)||sz(posC1)!=sz(posC2)) {
			cout << "NO" << '\n';
			continue;
		}
		int cnt=0;
		vector<int> numA1, numA2;
		for(int i=0; i<n; ++i) {
			if(str1[i]=='a') ++cnt;
			if(str1[i]=='c') {
				numA1.push_back(cnt);
				cnt=0;
			}
		}
		cnt=0;
		for(int i=0; i<n; ++i) {
			if(str2[i]=='a') ++cnt;
			if(str2[i]=='c') {
				numA2.push_back(cnt);
				cnt=0;
			}
		}
		bool valid=true;
		for(int i=0; i<sz(numA1); ++i)
			if(numA1[i]!=numA2[i]) {
				valid=false;
				break;
			}
		if(!valid) {
			cout << "NO" << '\n';
			continue;
		}
		
		vector<int> numBefore1, numAfter1, numBefore2, numAfter2;
		cnt=0;
		for(int i=0; i<n; ++i) {
			if(str1[i]=='a') cnt=0;
			if(str1[i]=='b') ++cnt;
			if(str1[i]=='c') numBefore1.push_back(cnt);
		}
		cnt=0;
		for(int i=0; i<n; ++i) {
			if(str2[i]=='a') cnt=0;
			if(str2[i]=='b') ++cnt;
			if(str2[i]=='c') numBefore2.push_back(cnt);
		}
		cnt=0;
		for(int i=n-1; i>=0; --i) {
			if(str1[i]=='a') numAfter1.push_back(cnt);
			if(str1[i]=='b') ++cnt;
			if(str1[i]=='c') cnt=0;
		}
		cnt=0;
		for(int i=n-1; i>=0; --i) {
			if(str2[i]=='a') numAfter2.push_back(cnt);
			if(str2[i]=='b') ++cnt;
			if(str2[i]=='c') cnt=0;
		}
		cnt=0;
		valid=true;
		for(int i=0; i<sz(posC1); ++i)
			if(numBefore1[i] < numBefore2[i]) valid=false;
		for(int i=0; i<sz(posA1); ++i)
			if(numAfter1[i] < numAfter2[i]) valid=false;
		cout << (valid?"YES":"NO") << '\n';
	}
}