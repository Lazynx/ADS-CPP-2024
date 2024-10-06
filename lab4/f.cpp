#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

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

int countTriangles(TreeNode* root) {
    if (root == nullptr) return 0;
    int count = 0;
    if (root->left && root->right) {
        count = 1;
    }
    return count + countTriangles(root->left) + countTriangles(root->right);
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

    cout << countTriangles(root) << endl;
    return 0;
}