#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

typedef struct Node {
	int key, priority, size;
	Node *left, *right;
	Node(int _key):key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(Node* newNode) {
		left=newNode;
		calcSize();
	}
	void setRight(Node* newNode) {
		right=newNode;
		calcSize();
	}
	void calcSize() {
		size=1;
		if(left) size+=left->size;
		if(right) size+=right->size;
	}
} Node;

pair<Node*, Node*> split(Node* root, int key) {
	if(root==NULL) return {NULL, NULL};
	if(root->key<key) {
		pair<Node*, Node*> rhs=split(root->right, key);
		root->setRight(rhs.first);
		return {root, rhs.second};
	}
	pair<Node*, Node*> lhs=split(root->left, key);
	root->setLeft(lhs.second);
	return {lhs.first, root};
}

Node* insert(Node* root, Node* newNode) {
	if(root==NULL) return newNode;
	int key=newNode->key;
	if(root->priority<newNode->priority) {
		pair<Node*, Node*> p=split(root, key);
		newNode->setLeft(p.first);
		newNode->setRight(p.second);
		return newNode;
	}
	if(root->key>key) 
		root->setLeft(insert(root->left, newNode));
	else
		root->setRight(insert(root->right, newNode));
	return root;
}

Node* merge(Node* a, Node* b) {
	if(a==NULL) return b;
	if(b==NULL) return a;
	if(a->priority<b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

Node* erase(Node* root, int key) {
	if(root==NULL) return root;
	if(root->key==key) {
		Node* ret=merge(root->left, root->right);
		delete root;
		return ret;
	}
	if(key<root->key) root->setLeft(erase(root->left, key));
	else root->setRight(erase(root->right, key));
	return root;
}

int kth(Node* root, int k) {
	int leftSize=0;
	if(root->left) leftSize=root->left->size;
	if(k<=leftSize) return kth(root->left, k);
	if(k==leftSize+1) return root->key;
	else return kth(root->right, k-leftSize-1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Node* root=new Node(1);
		stack<int> s;
		for(int i=2; i<=n; ++i) root=insert(root, new Node(i));
		vector<int> seq(n);
		for(int&a:seq) cin >> a;
		for(int i=n-1; i>=0; --i) {
			int k=kth(root, root->size-seq[i]);
			s.push(k);
			root=erase(root, k);
		}
		while(!s.empty()) {
			cout << s.top() << ' ';
			s.pop();
		}
		cout << '\n';
	}
}