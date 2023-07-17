//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int N)
    {
        //Your code here
        int ans = 0;
        while (true) {
            
            int maximum = INT_MIN;
            for(int i=0;i<N;i++){
                if(maximum<arr[i]){
                    maximum=arr[i];
                }
            }
            if(maximum==0){
                return ans;
            }
            for(int i=0;i<N;i++){
                arr[i]=min(arr[i],arr[i]^maximum);
            }
          ans=max(ans,ans^maximum);
        }
    //   return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
// } Driver Code Ends