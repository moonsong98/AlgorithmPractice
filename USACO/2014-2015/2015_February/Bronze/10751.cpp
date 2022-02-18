#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void) {
	int N; cin >> N;
	string str; cin >> str;
	vector<int> numC(N,0), numW(N,0);
	for(int i=1; i<N-1; ++i) numC[i]=numC[i-1]+(str[i-1]=='C');
	for(int i=N-2; i>=0; --i) numW[i]=numW[i+1]+(str[i+1]=='W');
	long long ans=0;
	for(int i=1; i+1<N; ++i) if(str[i]=='O') ans+=numC[i]*numW[i];
	cout << ans << '\n';
}