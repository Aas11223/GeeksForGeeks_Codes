//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        // Your code here
    //     int maxANDValue = 0;

    // // Check all pairs
    // for (int i = 0; i < N; i++) {
    //     for (int j = i + 1; j < N; j++) {
    //         int andValue = arr[i] & arr[j];
    //         if (andValue > maxANDValue) {
    //             maxANDValue = andValue;
    //         }
    //     }
    // }

    // return maxANDValue;
    
        int result = 0;
    
    // Iterate over each bit position from the most significant to the least significant
    for (int bit = 31; bit >= 0; --bit) {
        int count = 0;
        int tempResult = result | (1 << bit);
        
        // Count the number of elements with the current bit set
        for (int i = 0; i < N; ++i) {
            if ((arr[i] & tempResult) == tempResult) {
                count++;
            }
        }
        
        // If two or more elements have the current bit set, update the result
        if (count >= 2) {
            result = tempResult;
        }
    }
    
    return result;

    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends