//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void helper(vector<int> arr, int n,int index,int currSum,vector<int>& ans){
      if(index==n){
          ans.push_back(currSum);
          return;
      }
      helper(arr,n,index+1,currSum+arr[index],ans);
      helper(arr,n,index+1,currSum,ans);
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        
        vector<int> ans;
        helper(arr,n,0,0,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends