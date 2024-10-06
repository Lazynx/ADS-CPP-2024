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

void addChild(TreeNode* nodes[], int parent, int child, int isRight) {
    if (isRight == 0) {
        nodes[parent]->left = nodes[child];
    } else {
        nodes[parent]->right = nodes[child];
    }
}

int getMaxWidth(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int maxWidth = 0;
    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);
        for (int i = 0; i < count; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return maxWidth;
}

int main() {
    int n;
    cin >> n;
    TreeNode* nodes[n + 1];
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new TreeNode(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        addChild(nodes, x, y, z);
    }
    cout << getMaxWidth(nodes[1]) << endl;
    return 0;
}