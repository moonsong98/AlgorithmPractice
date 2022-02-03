#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int n; cin >> n;
	int cnt[26]={0,};
	for(int i=0; i<n; ++i) {
		string A, B; cin >> A >> B;
		int freq[2][26]={0,};
		for(int i=0; i<A.size(); ++i) freq[0][A[i]-'a']++;
		for(int i=0; i<B.size(); ++i) freq[1][B[i]-'a']++;
		for(int i=0; i<26; ++i) cnt[i]+=max(freq[0][i],freq[1][i]);
	}
	for(int i=0; i<26; ++i) cout << cnt[i] << '\n';
}