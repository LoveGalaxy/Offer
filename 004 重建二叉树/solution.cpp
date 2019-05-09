/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 前序第一个值就是二叉树根节点，然后找中序中的根节点位置
// 分割出左右子树
// 递归创建左右子树
// emmm 空 vector.size() 不是 0 而是 NULL
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == NULL){
            return NULL;
        }
        
        int val = pre[0];
        vector<int> pre_right;
        vector<int> pre_left;
        vector<int> vin_right;
        vector<int> vin_left;
        bool tag = false;
        
        for(int i=0; i < vin.size(); i++){
            if(vin[i] == val){
                tag = true;
                continue;
            }
            if(tag){
                vin_right.push_back(vin[i]);
                pre_right.push_back(pre[i]);
            }else{
                vin_left.push_back(vin[i]);
                pre_left.push_back(pre[i+1]);
            }
        }
        TreeNode* thisNode = new TreeNode(val);
        thisNode->right = reConstructBinaryTree(pre_right, vin_right);
        thisNode->left = reConstructBinaryTree(pre_left, vin_left);
        return thisNode;
    }
};