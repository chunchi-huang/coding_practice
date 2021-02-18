#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print2LevelVector(vector<vector<int>> vec) {

    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> levelOrder(TreeNode *root) {

    if (root == nullptr)
        return {};

    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();
        vector<int> temp;

        while (count--) {

            TreeNode *curr = q.front();
            q.pop();
            temp.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        res.push_back(temp);
    }

    return res;
}

int main() {
    //construct the tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrder(root);
    print2LevelVector(res);
}