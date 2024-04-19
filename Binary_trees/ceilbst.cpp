int findceil(Binarytree<int> *node , int k){
  int ceil=-1;
  while(root){
    if(root->value == k) {
      ceil=root->value;
      return ceil;
    }
    if(root->value <k){
      root->root->right;
    }
    else{
      ceil=root->value; //value badi toh hai but aur close badi dundni h ie chhoti dundni h
      root->root->left;
    }
    
  }
  return ceil;
}


int findfloor(Binarytree<int> *node , int k){
  int floor = -1;
  while(root){
    if(root->value==k){
      floor=root=>value;
      return floor;
    }
    if(root->value <k){
      floor= root->value;  //value choti h but aur chhoti dundhni hai 
      root= root->right;
    }
    else{
      root= root->left;  //jahan pe value badi h key se toh left side jakar chhoti value dundhege
    }
  }
}