#include<iostream>

using namespace std;

typedef struct Node {
	int key;
	struct Node *left, *right;
} Node;

int nodes[10001];

void insertion(Node* node, int key) {
	if(node->key > key) {
		if(node -> left != NULL) insertion(node->left, key);
		else {
			Node* newNode = new Node();
			newNode -> key = key;
			node -> left = newNode;
		}
		return;
	}	
	if(node -> right != NULL) insertion(node->right, key);
	else {
		Node* newNode = new Node();
		newNode -> key = key;
		node -> right = newNode;
	}
}

void postorder(Node* node) {
	if(node -> left) postorder(node->left);
	if(node -> right) postorder(node->right);
	cout << node->key << endl;
}

int main(void) {
	int i = 0;
	while(scanf("%d", &nodes[i++]) != EOF);
	Node* root = new Node;
	root -> key = nodes[0];
	--i;
	for(int it = 1; it < i; ++it)
		insertion(root, nodes[it]);
	
	postorder(root);
}