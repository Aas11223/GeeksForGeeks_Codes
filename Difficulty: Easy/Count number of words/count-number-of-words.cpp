//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int countWords(string s);
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	    {
	        string s;
	        getline(cin,s);
	        cout<<countWords(s)<<endl;
	    }
}
// } Driver Code Ends


//User function Template for C++

int countWords(string s)
{
    //code here.
    // int words=0;
    // for(int i=0;i<s.size();i++){
    //     //if(s[i]==' '|| s[i]=='\t' || s[i]=='\n') words++;
    //     if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
    //     {
    //         // Start of a new word
    //         if (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')
    //         {
    //             ++words;
    //         }
    //     }
    // }
    // //words+=1;
    // return words;
    
    int count = 0;
    string temp ="";
    
    for (int i=0 ; i<s.size() ; i++){
        if (s[i] >='a' && s[i] <= 'z'){
            temp = temp +s[i];
        }
        
        else if (s[i] ==' ' && temp !=""){
            count++;
            temp ="";
        }
        
        else if((s[i] =='\\'  && s[i+1] =='n' && temp != "") ||(s[i] =='\\'  && s[i+1] =='t' && temp != "") ){
            
            i++;
            count++;
            temp="";
        }
        
        else if (s[i]=='\\'  && temp == "")
        i++;
    }
    if (temp == ""){
        return count;
    }
    else 
    return count+1;
}