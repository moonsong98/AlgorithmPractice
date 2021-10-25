#include<iostream>
#include<vector>
#include<string>

using namespace std; 

string values[491];

string add(const string& A, const string& B) {
	string a(A.rbegin(), A.rend()), b(B.rbegin(), B.rend());
	vector<int> res;
	for(int i=0; i<b.size(); ++i) {
		if(A.size() <= i) res.push_back(b[i]-'0');
		else res.push_back(b[i]+a[i]-'0'-'0');
	}
	for(int i=0; i+1<res.size(); ++i) if(res[i]>=10) {
		res[i+1]+=res[i]/10;
		res[i]%=10;
	}
	if(res[res.size()-1]>=10) {
		res.push_back(res[res.size()-1]/10);
		res[res.size()-2]%=10;
	}
	
	string ret;
	for(int i=res.size()-1; i>=0; --i) ret+=res[i]+'0';
	return ret;
}

int main(void) {
	values[1]=values[2]="1";
	for(int i=3; i<=490; ++i) values[i]=add(values[i-2],values[i-1]);
	while(true) {
		int n;
		cin >> n;
		if(n==-1) break;
		cout << "Hour " << n << ": " << values[n] << " cow(s) affected" << '\n';
	}
}