#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode * root, long min, long max) {
    if (root == nullptr) return true;

    if (root->val <= min || root->val >= max) return false;

    return check(root->left, min, root->val) && check(root->right, root->val, max);
}

bool isValidBST(TreeNode * root) {

    return check(root, LONG_MIN, LONG_MAX);
} 

int main() {

    //example: root = [5,1,4,null,null,3,6]
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    TreeNode *left = root->left, *right = root->right;
    left->left = nullptr;
    left->right = nullptr;
    right->left = new TreeNode(3);
    right->right = new TreeNode(6);

    //example: root = [2,1,3]
    // TreeNode *root = new TreeNode(2);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(3);

    bool ans = false;
    // bool ans = true;
    bool output = isValidBST(root);
    
    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Correct! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }
}