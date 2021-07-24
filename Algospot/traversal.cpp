#include<iostream>
#include<vector>

using namespace std;

void traversal(const vector<int>& preorder, const vector<int>& inorder) {
	if(preorder.empty()) return;
	int root = preorder[0];
	int rootIndex;
	for(int i = 0; i < inorder.size(); ++i)
		if(root == inorder[i]) {
			rootIndex = i;
			break;
		}
	traversal(vector<int>(preorder.begin() + 1, preorder.begin() + rootIndex + 1), vector<int>(inorder.begin(), inorder.begin() + rootIndex));
	traversal(vector<int>(preorder.begin() + rootIndex + 1, preorder.end()), vector<int>(inorder.begin() + rootIndex + 1, inorder.end()));

	cout << root << " ";
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		vector<int> preorder;
		vector<int> inorder;
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			int a;
			cin >> a;
			preorder.push_back(a);
		}
		for(int i = 0; i < n; ++i){
			int a;
			cin >> a;
			inorder.push_back(a);
		}
		
		traversal(preorder, inorder);
		cout << endl;
	}
}