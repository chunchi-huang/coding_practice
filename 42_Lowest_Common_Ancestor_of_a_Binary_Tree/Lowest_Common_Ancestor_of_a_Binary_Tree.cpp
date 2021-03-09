#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findNode(TreeNode *root, vector<TreeNode *> &path, TreeNode *node)
{
    if (root == nullptr)
        return false;

    path.push_back(root);

    if (root->val == node->val)
        return true;

    if ((root->left && findNode(root->left, path, node)) || (root->right && findNode(root->right, path, node)))
        return true;

    path.pop_back();
    return false;
}

TreeNode *lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> path1, path2;

    if (findNode(root, path1, p) == false || findNode(root, path2, q) == false)
        return root;

    int i = 0;

    while (i < path1.size() && i < path2.size())
    {
        if (path1[i]->val != path2[i]->val)
            break;
        i++;
    }
    return path1[i - 1];
}

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == nullptr)
        return root;

    if (root->val == p->val || root->val == q->val)
        return root;

    TreeNode *left_lca = lowestCommonAncestor2(root->left, p, q);
    TreeNode *right_lca = lowestCommonAncestor2(root->right, p, q);

    if (left_lca && right_lca)
        return root;

    return (left_lca != nullptr) ? left_lca : right_lca;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;
    TreeNode *q = root->right;

    TreeNode *LCA1 = lowestCommonAncestor1(root, p, q);
    int ans_val = 3;

    if (LCA1->val == ans_val)
        cout << "Correct! The value of LCA1 is " << LCA1->val << endl;
    else
    {
        cout << "Wrong! The answer should be " << ans_val << endl;
        cout << "But the output is " << LCA1->val << endl;
    }

    TreeNode *LCA2 = lowestCommonAncestor2(root, p, q);

    if (LCA2->val == ans_val)
        cout << "Correct! The value of LCA2 is " << LCA2->val << endl;
    else
    {
        cout << "Wrong! The answer should be " << ans_val << endl;
        cout << "But the output is " << LCA2->val << endl;
    }
}