#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {

        val = data;
        left = NULL;
        //this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
public:
    vector<int> pre(TreeNode *root1)
    {

        vector<int> ans;
        preorder(root1, ans);

        return ans;
    }

    void preorder(TreeNode *root1, vector<int> &ans)
    {

        if (root1 == NULL)
        {
            return;
        }

        ans.push_back(root1->val);

        preorder(root1->left, ans);
        preorder(root1->right, ans);
    }

    void inorder(TreeNode *root1)
    {
        if (root1 == NULL)
            return;
        inorder(root1->left);
        cout << root1->val << " ";
        inorder(root1->right);
    }

    void postorder(TreeNode *root1)
    {
        if (root1 == NULL)
            return;

        postorder(root1->left);
        postorder(root1->right);
        cout << root1->val << " ";
    }

};

int main()
{
    BinaryTree b;

    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(6);
    root1->left->left->left = new TreeNode(4);
    root1->right = new TreeNode(3);
    root1->right->right = new TreeNode(5);
    b.postorder(root1);
    

    return 0;
}