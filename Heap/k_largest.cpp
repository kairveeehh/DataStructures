vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>k)
            minh.pop();
        }
        while(minh.size()>0)
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        reverse(ans.begin(), ans.end()); // as k largest dikhanee h but if order not imp we can print in any order
        return ans;
    }
    //min heap directly declare krne ki jgh jo array h usko heapify krenge build heap k through with the codition of min or max heap
    //and then the functions can remain the same
  
   //then we can use arr instead of minh after heapification
  //no we will have to use it like minh h and then work over rest