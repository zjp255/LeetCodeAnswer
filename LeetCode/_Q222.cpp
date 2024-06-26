// 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

// 完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//27ms 51% 29.16MB 16.46%
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        int ans = 0;
        bool isContinue = true;
        while(!que.empty())
        {
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = que.front();
                que.pop();
                ans++;
                if(!temp->left || !temp->right)
                {
                    ans += size - i - 1;
                    if(!temp->left)
                    {
                        ans += i * 2 ;
                    }
                    else{
                        ans += i * 2 + 1;
                    }
                    isContinue = false;
                    break;
                }

                que.push(temp->left);
                que.push(temp->right);
            }
            if(isContinue == false)
                break;
        }
        return ans;
    }
};