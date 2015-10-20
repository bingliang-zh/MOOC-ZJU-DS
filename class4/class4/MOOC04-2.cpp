#include <iostream>
#include <algorithm>
using namespace std;

class AVLNode {
public:
	int value;
	int height;
	AVLNode *lson;
	AVLNode *rson;
	AVLNode() {
		height = 1;
		lson = NULL;
		rson = NULL;
	}
};

int getHeight(AVLNode * tree) {
	if (tree) return tree->height;
	else return 0;
}

void updateHeight(AVLNode * tree) {
	tree->height = max(getHeight(tree->lson), getHeight(tree->rson)) + 1;
}

AVLNode * LLRotate(AVLNode * tree) {
	AVLNode * left = tree->lson;
	tree->lson = left->rson;
	left->rson = tree;

	updateHeight(tree);
	updateHeight(left);
	return left;
}

AVLNode * RRRotate(AVLNode * tree) {
	AVLNode * right = tree->rson;
	tree->rson = right->lson;
	right->lson = tree;

	updateHeight(tree);
	updateHeight(right);
	return right;
}

AVLNode * LRRotate(AVLNode * tree) {
	AVLNode * left = tree->lson;
	AVLNode * root = left->rson;
	tree->lson = root->rson;
	left->rson = root->lson;
	root->lson = left;
	root->rson = tree;

	updateHeight(left);
	updateHeight(tree);
	updateHeight(root);
	return root;
}

AVLNode * RLRotate(AVLNode * tree) {
	AVLNode * right = tree->rson;
	AVLNode * root = right->lson;
	tree->rson = root->lson;
	right->lson = root->rson;
	root->lson = tree;
	root->rson = right;

	updateHeight(tree);
	updateHeight(right);
	updateHeight(root);
	return root;
}

AVLNode * insert(AVLNode * tree, int var) {
	if (tree == NULL) {
		tree = new AVLNode;
		tree->value = var;
	}
	else if (var < tree->value) {
		tree->lson = insert(tree->lson, var);
	}
	else if (var > tree->value) {
		tree->rson = insert(tree->rson, var);
	}
	updateHeight(tree);
	return tree;
}

int main() {
	int N;
	cin >> N;
	AVLNode * tree = NULL;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		tree = insert(tree, temp);
	}

	cout << tree->value << endl;

	system("pause");
	return 0;
}