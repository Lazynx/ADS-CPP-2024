#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    return findNode(root->right, val);
}

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int N;
    cin >> N;
    vector<int> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i];
    }

    TreeNode* root = nullptr;
    for (int val : nodes) {
        root = insert(root, val);
    }

    int target;
    cin >> target;
    TreeNode* targetNode = findNode(root, target);
    preorderTraversal(targetNode);
    cout << endl;

    return 0;
}