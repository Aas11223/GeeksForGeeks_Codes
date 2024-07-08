//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
// 		void helper(string S, int index,vector<string>& ans){
// 		    if(index==S.size()) ans.push_back(S);
// 		    for(int i=index;i<S.size();i++){
// 		        if(i>index && S[i]==S[i-1]) continue;
// 		        swap(S[index],S[i]);
// 		        helper(S,index+1,ans);
// 		        swap(S[index],S[i]);
// 		    }
// 		}
// 		vector<string>find_permutation(string S)
// 		{
// 		    // Code here there
// 		    vector<string> ans;
// 		    sort(S.begin(), S.end());
// 		    helper(S,0,ans);
// 		    return ans;
// 		}
void helper(string S, int index, vector<string>& ans) {
        if (index == S.size()) {
            ans.push_back(S);
            return;
        }
        unordered_set<char> seen;  // To track characters already processed at the current index
        for (int i = index; i < S.size(); i++) {
            if (seen.find(S[i]) != seen.end()) continue;  // Skip duplicates
            seen.insert(S[i]);
            swap(S[index], S[i]);
            helper(S, index + 1, ans);
            swap(S[index], S[i]); // backtrack
        }
    }

    vector<string> find_permutation(string S) {
        vector<string> ans;
        helper(S, 0, ans);
        sort(ans.begin(), ans.end()); // To return the permutations in sorted order
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends