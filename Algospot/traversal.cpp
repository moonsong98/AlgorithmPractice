#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

vector<int> preorder, inorder;

void traversal(int l1, int r1, int l2, int r2) {
	if(l1==r1) {
		cout << preorder[l1] << ' ';
		return;
	}
	int root = preorder[l1];
	int leftSize=0, rightSize;
	for(int i=l2; i<=r2; ++i)
		if(root == inorder[i]) {
			leftSize=i-l2;
			break;
		}
	rightSize=r1-l1-leftSize;
	if(leftSize)
		traversal(l1+1, l1+leftSize, l2, l2+leftSize-1);
	if(rightSize)
		traversal(l1+leftSize+1, r1, l2+leftSize+1, r2);
	cout << root << " ";
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		preorder=vector<int>(n);
		inorder=vector<int>(n);
		for(int& a: preorder) cin >> a;
		for(int& a: inorder) cin >> a;
		traversal(0, n-1, 0, n-1);
		cout << '\n';
	}
}