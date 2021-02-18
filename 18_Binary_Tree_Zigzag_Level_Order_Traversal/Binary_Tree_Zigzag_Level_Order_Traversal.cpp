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

void print2LevelVector(vector<vector<int>> vec)
{

    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[i].size(); ++j)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    if (root == nullptr)
        return {};

    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = false;

    while (q.empty() == false)
    {
        int count = q.size();
        vector<int> tmp;

        while (count--)
        {
            TreeNode *curr = q.front();
            q.pop();
            tmp.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        if (flag)
            reverse(tmp.begin(), tmp.end());
        flag = !flag;
        res.push_back(tmp);
    }
    return res;
}

int main()
{
    //construct the tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = zigzagLevelOrder(root);
    print2LevelVector(res);
}