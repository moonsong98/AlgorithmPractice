#include<iostream>
#include<vector>

using namespace std;

vector<int> preorder;
vector<int> inorder;

void postorder(int pl, int pr, int il, int ir) {
	if(pl == pr) return;
	int root = preorder[pl];
	int leftSize;
	for(int i = il; i < ir; ++i)
		if(inorder[i] == root)
			leftSize = i;
	leftSize -= il;
	
	postorder(pl + 1, pl + 1 + leftSize, il, il + leftSize);
	postorder(pl + 1 + leftSize, pr, il + leftSize + 1, ir);
	cout << root << ' ';
}

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		preorder = vector<int>();
		inorder = vector<int>();
		for(int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			preorder.push_back(a);
		}
		for(int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			inorder.push_back(a);
		}
		postorder(0, preorder.size(), 0, inorder.size());
		cout << endl;
	}
}