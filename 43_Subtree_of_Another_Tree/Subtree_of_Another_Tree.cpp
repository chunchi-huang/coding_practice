#include <iostream>

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

bool isEqual(TreeNode *p, TreeNode *q)
{

    if (p == nullptr || q == nullptr)
        return (p == q);
    else
    {
        return (p->val == q->val) && isEqual(p->left, q->left) && isEqual(p->right, q->right);
    }
}

bool isSubtree(TreeNode *s, TreeNode *t)
{

    if (s == nullptr || t == nullptr)
        return (s == t);
    else
    {
        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
}

int main() {

    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);

    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    bool ans = true;
    bool output = isSubtree(s,t);

    if (output == ans)
        cout << "Correct! The answer is " << output << endl;
    else {
        cout << "Wrong! The answer should be " << ans << endl;
        cout << "But the output is " << output << endl;
    }

}
