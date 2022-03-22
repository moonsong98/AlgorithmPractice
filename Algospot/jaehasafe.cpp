#include<iostream>
#include<vector>

#define sz(N) (int)N.size()

using namespace std;

int kmp(string H, string N) {
	vector<int> fail(sz(N), 0);
	for(int i=1, j=0; i<sz(N); ++i) {
		while(j>0&&N[i]!=N[j]) j=fail[j-1];
		if(N[i]==N[j]) fail[i]=++j;
	}
	for(int i=0, j=0; i<sz(H); ++i) {
		while(j>0 && H[i]!=N[j]) {
			j=fail[j-1];
		}
		if(H[i]==N[j]) {
			++j;
			if(j==sz(N)) 
				return i-j+1;
		}
	}
	return sz(N);
}

int main(void) {
	int T;
	cin >> T;
	while(T--) {
		int ans=0, n;
		string str1, str2;
		cin >> n >> str1;
		for(int i=0; i<n; ++i) {
			cin >> str2;
			ans+=(i%2==0 ? kmp(str2+str2, str1): kmp(str1+str1, str2));
			str1=str2;
		}
		cout << ans << '\n';
	}
}