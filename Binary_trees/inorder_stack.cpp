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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
     stack<TreeNode*> st;
     TreeNode* node = root;
     vector<int> ans;
     while(true){
        if(node !=NULL){
            st.push(node);    // take the root check for the left then for the value and then for the right
            node=node->left;        } //left
            else{
                if(st.empty()==true)break;
                node=st.top();
                st.pop();
                ans.push_back(node->val); //root
                node=node->right; //right
            }
            }
            return ans;
     }
     };


//inorder traversal for a bst is always sorted     