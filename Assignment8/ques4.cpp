#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTreeFromString(const string& s) {
    if (s.empty()) {
        return nullptr;
    }

    stack<TreeNode*> stk;
    TreeNode* root = nullptr;
    int num = 0;
    bool isNegative = false;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '-') {
            isNegative = true;
        } else if (c == '(') {
            TreeNode* node = new TreeNode(isNegative ? -num : num);
            if (!stk.empty()) {
                TreeNode* parent = stk.top();
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
            stk.push(node);
            num = 0;
            isNegative = false;
        } else if (c == ')') {
            stk.pop();
        }
    }

    if (!stk.empty()) {
        root = stk.top();
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    string s = "4(2(3)(1))(6(5))";
    TreeNode* root = constructTreeFromString(s);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
