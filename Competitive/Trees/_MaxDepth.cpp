#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int data;
	TreeNode*left;
	TreeNode*right;

	TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

class solution {

public:
	int maxDepth(TreeNode * root) {
		if (root == NULL)
			return 0;
		else {
			int lDepth = maxDepth(root->left);
			int rDepth = maxDepth(root->right);

			if (lDepth > rDepth)
				return (lDepth + 1);
			else return (rDepth + 1);

		}
	}

// DFS Approach
	int maxDepthDfs(TreeNode* root) {
		return root == NULL ? 0 : max(maxDepthDfs(root->left), maxDepthDfs(root->right)) + 1;
	}

	int maxDepthBfs(TreeNode* root) {
		if (root == NULL)
			return 0;
		int res = 0;
		queue<TreeNode *>q;
		q.push(root);
		while (!q.empty()) {
			++res;
			for (int i = 0 , n = q.size(); i < n; ++i) {
				TreeNode *p = q.front();
				q.pop();

				if (p->left != NULL)
					q.push(p->left);
				if (p->right != NULL)
					q.push(p->right);
			}
		}
		return res;
	}
};

int main() {
	solution s;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	cout << "Height of tree is " << s.maxDepth(root) << endl;
	cout << "Height of tree is " << s.maxDepthDfs(root) << endl;
	cout << "Height of tree is " << s.maxDepthBfs(root) << endl;
	return 0;
}
