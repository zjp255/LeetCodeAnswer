// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

// 一般来说，删除节点可分为两个步骤：

// 首先找到需要删除的节点；
// 如果找到了，删除它。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//24ms 70.21% 32.75Mb 5.06%
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            if (root->right == nullptr && root->left != nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            if (root->right != nullptr && root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right != nullptr && root->left != nullptr)
            {
                TreeNode* temp = root->right;
                while(temp->left != nullptr)
                {
                    temp = temp->left;
                }
                temp->left = root->left;
                temp = root->right;
                delete root;
                return temp;
            }
        }
        if(key > root->val) root->right = deleteNode(root->right,key);
        if(key < root->val) root->left = deleteNode(root->left, key);
        return root;
    }
};


//23ms 78.07% 32.75Mb 5.24%
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* pre = nullptr;
        TreeNode* temp = root;
        while (temp)
        {
            if(key > temp->val)
            {
                pre = temp;
                temp = temp->right;
            }
            else if(key < temp->val)
            {
                pre = temp;
                temp = temp->left;
            }
            else{
                if(temp->right != nullptr)
                {
                    TreeNode* leftNode = temp->left;
                    TreeNode* rightNode = temp->right;
                    temp->val = rightNode->val;
                    temp->right = rightNode->right;
                    temp->left = rightNode->left;
                    if(temp->left == nullptr)
                    {
                        temp->left = leftNode;
                        break;
                    }
                    else{
                        while (rightNode->left)
                        {
                            rightNode = rightNode->left;
                        }
                        rightNode->left = leftNode;
                        break;
                    }
                }else{
                    TreeNode* leftNode = temp->left;
                    if(leftNode == nullptr)
                    {
                        if(pre == nullptr)
                            return nullptr;
                        else
                        {
                            if(pre->left == temp)
                            {
                                pre->left = nullptr;
                            }
                            else{
                                pre->right = nullptr;
                            }
                        }
                        delete temp;
                        break;
                    }
                    temp->val = leftNode->val;
                    temp->left = leftNode->left;
                    temp->right = leftNode->right;
                    break;
                }
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(0);
    Solution s;
    s.deleteNode(root,0);
    return 0;
}
