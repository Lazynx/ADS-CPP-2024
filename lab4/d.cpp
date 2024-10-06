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

void levelOrderSum(TreeNode* root, vector<int>& levelSums) {
    if (root == nullptr) return;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (level == levelSums.size()) {
            levelSums.push_back(0);
        }
        levelSums[level] += node->val;
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
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

    vector<int> levelSums;
    levelOrderSum(root, levelSums);

    cout << levelSums.size() << endl;
    for (int sum : levelSums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}