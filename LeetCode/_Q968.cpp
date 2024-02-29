// 给定一个二叉树，我们在树的节点上安装摄像头。

// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

// 计算监控树的所有节点所需的最小摄像头数量。
 
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
 //无法通过测试
class Solution {
public:
      int ans1 = 0;
    int ans2 = 0;
    int layerCount = 0;
    int minCameraCover(TreeNode* root) {
        traversal(root,0);
        if(ans1 == ans2)
        {
            if(ans1 % 2 == 0)
            {
                return ans1;
            }
            return ans1 - 1 == 0?1:ans1 - 1;
        }
        else{
            return min(ans1,ans2) == 0?1:min(ans1,ans2);
        }
        
        /*
        if(layerCount % 2 == 0 && layerCount != 0)
        {  
            return ans1;
        }else{
            return ans2;
        }
        */
    }

    void traversal(TreeNode* root, int layer)
    {
        if(root == NULL)
        {
            if(layer - 1> layerCount)
            {
                layerCount = layer - 1;
            }
            return ;
        }else{ 
            if(layer % 2 == 1)
            {
                ans1++;
            }else{
                ans2++;
            }
        }
        traversal(root->left,layer + 1);
        traversal(root->right,layer + 1);
    }
};