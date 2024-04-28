#include<iostream>
#include<vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;

void traversal(int inorderLeft, int inorderRight, int postorderLeft, int postorderRight) {
	if(inorderLeft == inorderRight) return;
	int root = postorder[postorderRight - 1];
	int rootIndex;
	for(int i = inorderLeft; i < inorderRight; ++i)
		if(inorder[i] == root) {
			rootIndex = i;
			break;
		}
	rootIndex -= inorderLeft;
	
	cout << root << " ";
	traversal(inorderLeft, inorderLeft + rootIndex, postorderLeft, postorderLeft + rootIndex);
	traversal(inorderLeft + rootIndex + 1, inorderRight, postorderLeft + rootIndex, postorderRight - 1);
}

int main(void) {
	cin.sync_with_stdio(false);
	int n;
	
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		inorder.push_back(a);
	}
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		postorder.push_back(a);
	}
	
	traversal(0, n, 0, n);
}