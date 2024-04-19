//max heap k way m heapifykrdenge

for(int i=0;i<n;i++)
        {
            maxh.push(arr[i]);
            if(maxh.size()>k)
            maxh.pop();
        }

return maxh.top();        