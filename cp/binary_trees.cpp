#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node *left, *right;
	node() {val = 0, left = right = NULL;}
	node(int _val) {val = _val, left = right = NULL;}
};

node* build_tree_preorder() {
	int x;
	cin >> x;
	if (x == -1) return NULL;

	node* cur = new node(x);
	cur->left = build_tree_preorder();
	cur->right = build_tree_preorder();

	return cur;
}

void preorder(node* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void postorder(node* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

// build tree using level order traversal
node* build_tree_levelOrder() {
	int x;
	cin >> x;
	if (x == -1) return NULL;
	node *root = new node(x);

	queue<node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		node *cur = Q.front();
		Q.pop();

		int x, y;
		cin >> x >> y;
		if (x != -1) {
			cur->left = new node(x);
			Q.push(cur->left);
		}
		if (y != -1) {
			cur->right = new node(y);
			Q.push(cur->right);
		}
	}
	return root;
}

void level_order_traversal(node* root) {
	queue<node*> Q;
	Q.push(root);

	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		cout << cur->val << " ";

		if (cur->left != NULL) {
			Q.push(cur->left);
		}
		if (cur->right != NULL) {
			Q.push(cur->right);
		}
	}
}

//
void zigZagTraversal(node* root) {

}

int sizeOfTree(node* root) {
	if (root == NULL) return false;
	return sizeOfTree(root->left) + sizeOfTree(root->right) + 1;
}

int heightOfTree(node* root) {
	if (root == NULL) return 0;
	return max(heightOfTree(root->left),
	           heightOfTree(root->right)) + 1;
}

int sumTree(node* root) {
	if (root == NULL) return 0;
	return sumTree(root->left) + sumTree(root->right) + root->val;
}

// print at level k

void leftViewOfTree(node *root) {
	queue<node*> Q;
	Q.push(NULL);
	Q.push(root);
	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		if (cur == NULL) {
			if (!Q.empty()) {
				cout << Q.front()->val << " ";
				Q.push(NULL);
			}
		}
		else {
			if (cur->left != NULL) {
				Q.push(cur->left);
			}
			if (cur->right != NULL) {
				Q.push(cur->right);
			}
		}
	}
}

void rightViewOfTree(node* root) {
	if (root == NULL) return;
	queue<node*> Q;
	Q.push(NULL);
	Q.push(root);
	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();

		if (cur == NULL) {
			if (!Q.empty()) {
				cout << Q.front()->val << " ";
				Q.push(NULL);
			}
		}
		else {
			if (cur->right != NULL) {
				Q.push(cur->right);
			}
			if (cur->left != NULL) {
				Q.push(cur->left);
			}
		}

	}
}

bool isSameTree(node* p, node* q) {
	if (q == NULL && p == NULL) return true;
	if (p == NULL || q == NULL) return false;

	return isSameTree(p->left, q->left)
	       && isSameTree(p->right, q->right)
	       && p->val == q->val;
}

node* invertTree(node* root) {
	if (root == NULL) return NULL;
	swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// node* root = build_tree_preorder();

	// 1 2 3 4 5 7 6
	// preorder(root);
	// postorder(root);

	node *root = build_tree_levelOrder();
	// preorder(root);
	// inorder(root);
	// postorder(root);
	// level_order_traversal(root);

	// cout << sizeOfTree(root) << '\n';

	// cout << heightOfTree(root) << '\n';

	leftViewOfTree(root);

	rightViewOfTree(root);







}