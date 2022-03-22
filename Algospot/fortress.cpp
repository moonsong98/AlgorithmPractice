#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

typedef struct TreeNode {
	int y, x, r, h, d;
	vector<TreeNode*> children;
	TreeNode(int _x, int _y, int _r): x(_x), y(_y), r(_r) {}
} TreeNode;

void insert(TreeNode *u, TreeNode *v) {
	auto isContained=[=](TreeNode* a, TreeNode* b)->int{
		return (a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y) <= (a->r+b->r)*(a->r+b->r);
	};
	for(TreeNode *c:u->children)
		if(isContained(c, v)) {
			insert(c, v);
			return;
		}
	u->children.push_back(v);
}

int calcMaxDistance(TreeNode* root) {
	if(sz(root->children)==0) return root->h=root->d=0;
	int ret=0;
	for(TreeNode* c: root->children) ret=max(ret, calcMaxDistance(c));
	if(sz(root->children)==1) {
		root->h=root->children[0]->h+1;
		ret=max(ret, root->h);
	}
	if(sz(root->children)>=2) {
		vector<int> h;
		for(TreeNode* c: root->children) h.push_back(-(c->h));
		sort(h.begin(), h.end());
		root->h=-h[0]+1;
		ret=max(ret, -h[0]-h[1]+2);
	}
	return root->d=ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int y, x, r, n; cin >> n;
		cin >> x >> y >> r;
		TreeNode* root=new TreeNode(x, y, r);
		for(int i=0; i+1<n; ++i) {
			cin >> x >> y >> r;
			TreeNode* newNode=new TreeNode(x, y, r);
			insert(root, newNode);
		}
		cout << calcMaxDistance(root) << '\n';
	}
}