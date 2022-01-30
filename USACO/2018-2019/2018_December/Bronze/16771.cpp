#include<iostream>
#include<set>

using namespace std;

int main(void) {
	int A[10], B[10];
	for(int i=0; i<10; ++i) cin >> A[i];
	for(int i=0; i<10; ++i) cin >> B[i];
	set<int> elA, elB, pairA, pairB;
	for(int i=0; i<10; ++i) elA.insert(A[i]);
	for(int i=0; i<10; ++i) elB.insert(B[i]);
	for(int i=0; i<10; ++i) for(int j=i+1; j<10; ++j) pairA.insert(A[i]+A[j]);
	for(int i=0; i<10; ++i) for(int j=i+1; j<10; ++j) pairB.insert(B[i]+B[j]);
	
	set<int> posValues;
	for(set<int>::iterator itr=elA.begin(); itr!=elA.end(); ++itr) for(set<int>::iterator itr2=elB.begin(); itr2!=elB.end(); ++itr2) posValues.insert(1000+(*itr2)-(*itr));
	for(set<int>::iterator itr=pairA.begin(); itr!=pairA.end(); ++itr) for(set<int>::iterator itr2=pairB.begin(); itr2!=pairB.end(); ++itr2) posValues.insert(1000+(*itr2)-(*itr));
	posValues.insert(1000);
	cout << posValues.size() << '\n';
}