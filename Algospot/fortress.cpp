#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct TreeNode {
	int x, y, r;	
	vector<struct TreeNode*> children;
	int nodeNumber;
	int maxDepth;
	int maxLength;
} TreeNode;

TreeNode* root;

bool isContained(TreeNode* A, TreeNode*B) {
	return (A->x - B->x) * (A->x - B->x) + (A -> y - B->y)*(A->y - B->y) < (A->r + B->r) * (A->r + B->r);
}

void insertNode(TreeNode* node, TreeNode* newNode) {
	for(int i = 0; i < node->children.size(); ++i) {
		TreeNode* child = node->children[i];
		if(isContained(child, newNode)) {
			if(child->r > newNode-> r) {
				insertNode(child, newNode);
				return;
			}
			else {
				node->children[i] = newNode;
				newNode->children.push_back(child);
				return;
			}
		}
	}
	node->children.push_back(newNode);
}

int calcMaxDepth(TreeNode* node) {
	node -> maxDepth = 0;
	if(node->children.size() == 0) return 0;
	for(int i = 0; i < node->children.size(); ++i)	
		node -> maxDepth = max(node -> maxDepth, calcMaxDepth(node->children[i])+1);
	return node -> maxDepth;
}

// void printMaxDepth(TreeNode* node) {
// 	cout << node->maxDepth << endl;
// 	for(int i = 0; i < node->children.size(); ++i)
// 		printMaxDepth(node->children[i]);
// 	return;
// }

bool cmp(TreeNode* A, TreeNode* B) {
	return A->maxDepth > B->maxDepth;	
}

int calcMaxLength(TreeNode* node) {
	node -> maxLength = 0;
	if(node->children.size() == 0) return 0;
	for(int i = 0; i < node->children.size(); ++i)
		node->maxLength = max(node->maxLength, calcMaxLength(node->children[i]));
	sort(node->children.begin(), node->children.end(), cmp);
	if(node->children.size() == 1) node -> maxLength = max(node->maxLength, node->children[0]->maxDepth + 1);
	else node->maxLength = max(node->maxLength, node->children[0]->maxDepth + node->children[1]->maxDepth + 2);
	return node->maxLength;
}

void solve() {
	int n;
	cin >> n;	
	
	for(int i = 0; i < n; ++i) {
		TreeNode* node = new TreeNode;
		cin >> node-> x >> node -> y >> node->r;
		if(i == 0) root = node;
		else insertNode(root, node);
	}
	calcMaxDepth(root);
	cout << calcMaxLength(root) << endl;
	// printMaxDepth(root);
	
	// cout << root->children.size() << endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}