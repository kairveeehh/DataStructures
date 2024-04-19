void heapify(int arr[] , int n , int i){
  int largest = i;
  int left= 2*i;
  int right= 2*i+1;
  if(left< n && arr[largest]<arr[left]){
    largest=left; // check  for chhota change 
  //one based indexing m =  bhi laga denge
}
  if(right<n && arr[largest]<arr[right]){
    largest = right;}  //check for bada change

 if(largest !=i){ // yaani kuch change hua haiii pehli and baad wali pos m 
  swap(arr[i],arr[largest]);
  heapify(arr,n,largest); // aage ka check krne k liyee
 }   


 in arr[];
 int n= arr.size();
 for(int i = n/2-1 ; i>=0 ; i--){
  heapify(arr,n,i);
 }


 void heapsort(arr[], int n ){
  int t= n ; //t=size
  while(t>1){
    swap(arr[t] . arr[1]){
      t--;
      heapify(arr,t,1);
    }
  }
 }