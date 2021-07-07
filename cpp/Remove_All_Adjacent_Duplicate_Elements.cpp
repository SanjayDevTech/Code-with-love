//Returns the final string after all such duplicate removals have been made.

/*
 * Input: "abbaca"
 * Output: "ca"
 * Explanation: 
 * For example, in "abbaca" we could remove "bb" since the letters are
 * adjacent and equal, and this is the only possible move.  The result
 * of this move is that the string is "aaca", of which only "aa" is possible,
 * so the final string is "ca".
 */  

string removeDuplicates(string s) {
        string st;
        int last=-1;  //top element position in resultant string
        for(int i=0;i<s.length();i++){
            if(last>-1&&st[last]==s[i]){   // when current matches last means we should pop element from string
                st.pop_back();
                last--;
                
            }
            else {     //else push element
              st.push_back(s[i]);
              last+=1;
            }  
        }
        return st;
}
