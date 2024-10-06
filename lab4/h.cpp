#include <iostream>
#include <vector>
#include <algorithm>

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

void transformToGreaterSumTree(TreeNode* root, int& sum) {
    if (root == nullptr) return;
    transformToGreaterSumTree(root->right, sum);
    sum += root->val;
    root->val = sum;
    transformToGreaterSumTree(root->left, sum);
}

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
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

    int sum = 0;
    transformToGreaterSumTree(root, sum);

    vector<int> result;
    inorderTraversal(root, result);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}