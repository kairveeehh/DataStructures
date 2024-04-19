class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val ==key) return helper(root);

        TreeNode* d = root;
        while(root!= NULL){
            if(root->val >key){
                if(root->left!=NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root= root->left;
                }
            } else{
                if(root->right!=NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root= root->right;
                }
            }

        }
        return d;
    }

    TreeNode* helper(TreeNode* root){
        if(root->right==NULL) return root->left;
        if(root->left ==NULL) return root->right;
        TreeNode* rightc = root->right;
        TreeNode* lr = findlastright(root->left);
        lr->right = rightc;
        return root->left;

    }



    TreeNode* findlastright(TreeNode* root){
        if(root->right==NULL) return root;
        else return findlastright(root->right);

        
    }
};