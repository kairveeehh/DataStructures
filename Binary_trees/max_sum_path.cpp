//hard qus of leetcode
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        ms(root, res);
        return res;
    }
    int ms(TreeNode* root, int &res) {
        if (root == NULL)
            return 0;

        int lh=  max(0 ,ms(root->left , res)); // to avoid the negative ones being taken as the maximum sum
        int  rh = max( 0 ,ms(root->right  ,res));
        res= max(res , lh+rh+root->val); //will give the max sum
        return max(lh, rh) +root->val;    //for one inidividual case this calculates the sum around teh cirved path of teh node

    }
};