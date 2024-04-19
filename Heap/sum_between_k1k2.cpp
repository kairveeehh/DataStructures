//make a function of k smallest once that takes an array and k 
//ek heap declare kr denge nayi si 
int kth smallest( int arr[] , int k ){
  heap h; //class declared hogi heap ki with functions as push pop top 
  for(int i =0 ; i<size ; i++){
    h.push(arr[i]);
    if(h.size()>k){
      h.pop();
    }}
  return h.top(); // return root node of respective min or max heap
  }

//do this again with k = k2 and then ek baar array traverse kr k && condition se find out krlo  