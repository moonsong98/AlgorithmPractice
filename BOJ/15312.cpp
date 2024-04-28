#include<iostream>
#include<vector>
#include<string>

using namespace std;

int numWrite[]={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main(void) {
	string A, B;
	cin >> A >> B;
	vector<int> seq(A.size()*2);
	for(int i=0; i<A.size(); ++i) seq[i*2]=numWrite[A[i]-'A'];
	for(int i=0; i<A.size(); ++i) seq[i*2+1]=numWrite[B[i]-'A'];
	for(int i=A.size()*2; i>2; --i) {
		vector<int> tmp(i-1);
		for(int j=0; j<i-1; ++j) tmp[j] = (seq[j]+seq[j+1])%10;
		for(int j=0; j<i-1; ++j) seq[j] = tmp[j];
	}
	cout << seq[0] << seq[1] << '\n';
}