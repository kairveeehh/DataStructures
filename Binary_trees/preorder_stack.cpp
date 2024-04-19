/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//preorder m we reversed the order so as to make the order of root left right successful
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root ==NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root= st.top(); //to make sure that we print top in the beginnibng itself
            st.pop();
            ans.push_back(root->val);
            if(root->right!=NULL){ //to reverse the preorderroot left right and as stack is lifo 
                st.push(root->right);

            }
            if(root->left !=NULL){
                st.push(root->left);
            }
        }
        return ans;}};
   
