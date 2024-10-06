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

bool isPathAvailable(TreeNode* root, const string& path) {
    TreeNode* current = root;
    for (char direction : path) {
        if (current == nullptr) return false;
        if (direction == 'L') {
            current = current->left;
        } else if (direction == 'R') {
            current = current->right;
        }
    }
    return current != nullptr;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i];
    }

    TreeNode* root = nullptr;
    for (int val : nodes) {
        root = insert(root, val);
    }

    for (int i = 0; i < M; ++i) {
        string path;
        cin >> path;
        if (isPathAvailable(root, path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
