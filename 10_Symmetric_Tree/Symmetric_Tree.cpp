#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* left, TreeNode* right) {
    
    if (left == nullptr && right == nullptr) return true;

    if (left == nullptr || right == nullptr) return false;

    return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;

    return helper(root->left, root->right);
}

int main() {

    //example: root = [1,2,2,3,4,4,3]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    TreeNode *left = root->left, *right = root->right;
    left->left = new TreeNode(3);
    left->right = new TreeNode(4);
    right->left = new TreeNode(4);
    right->right = new TreeNode(3);

    //example: root = [1,2,2,null,3,null,3]
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);
    // TreeNode *left = root->left, *right = root->right;
    // left->left = nullptr;
    // left->right = new TreeNode(3);
    // right->left = nullptr;
    // right->right = new TreeNode(3);

    bool ans = true;
    // bool ans = false;
    bool output = isSymmetric(root);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Correct! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }

}

