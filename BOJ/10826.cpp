#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string add(const string& A, const string& B) {
	if(A.size()<B.size()) return add(B, A);
	vector<int> res;
	string revA(A.rbegin(), A.rend()), revB(B.rbegin(), B.rend());
	for(int i=0; i<max(A.size(), B.size()); ++i) {
		if(B.size() <= i) res.push_back(revA[i]-'0');
		else res.push_back(revA[i]+revB[i]-'0'*2);
	}
	for(int i=0; i<res.size(); ++i) {
		if(res[i]>=10) {
			if(i==res.size()-1) res.push_back(res[i]/10);
			else res[i+1]+=res[i]/10;
			res[i]%=10;
		}
	}
	string ans;
	for(int n:res) ans.push_back('0'+n);
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(void) {
	vector<string> fibo(1e4+1);
	fibo[0]="0"; fibo[1]="1";
	for(int i=2; i<=1e4; ++i) fibo[i]=add(fibo[i-1],fibo[i-2]);
	int n; cin >> n; cout << fibo[n] << '\n';
}