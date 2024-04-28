#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

string A, B;
void postorder(int l1, int r1, int l2, int r2) {
	if(l1==r1) {
		cout << A[l1];
		return;
	}
	int leftSize=0, rightSize;
	for(int i=l2; i<=r2; ++i)
		if(B[i]==A[l1]) {
			leftSize=i-l2;
			break;
		}
	rightSize=r2-l2-leftSize;
	if(leftSize)
		postorder(l1+1, l1+leftSize, l2, l2+leftSize-1);
	if(rightSize)
		postorder(l1+leftSize+1, r1, l2+leftSize+1, r2);
	cout << A[l1];
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while(true) {
		cin >> A >> B;
		if(cin.eof()) break;
		postorder(0, sz(A)-1, 0, sz(B)-1);
		cout << '\n';
	}
}