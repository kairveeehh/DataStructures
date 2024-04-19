TreeNode* searchBST(Node* node , int val){
  while(node!=NULL && node->val !=val){
    if(node->val <val) node=node->right;
    else node=node->left;
  }
  return node;
}