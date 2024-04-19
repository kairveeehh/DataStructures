//using the num wala concept num=1 push in pre and num++ aur fir top se cmp kro
class solution{
  public:
   vector<int> solve(TreeNode8 root){
    stack<pair<TreeNode* , int>> st;
    st.push({root , 1});
    vector<int> pre , in , post;
    if(root==NULL) return ;
    while(!st,empty()){
      autp it = st.top();
      st.pop(); //ek baar bahar nikal k fir val badha k pushing back

      //condition checking beginning
      if(it.second ==1){
        pre.push_back(it.first->val);
        it.second++;
        st.push(it);
        if(it.first-> !=NULL){ //1 k baad left check
          st,push({it.first->left ,1});
        }
      }
      else if(it.second ==2){
        in,push_back(it.first->val);
        it.second++;
        st.push(it);
        if(it.first->right !=NULL){ // 2 kbaad right check
        st.push({it.first->right ,1});
      }


    }
    else{
      post.push_back(it.first->val);
    }
   }
}
};