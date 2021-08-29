class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        int maxi=arr[0].dead;
        for(int i=1;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        
        vector<int> slot(maxi+1,-1);
        int count=0,prof=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=i;
                    count++;
                    prof=prof+arr[i].profit;
                    break;
                }
                
            }
        }
        
        vector<int> ans(2);
        ans[0]=count;
        ans[1]=prof;
        return ans;
        
    } 
};
