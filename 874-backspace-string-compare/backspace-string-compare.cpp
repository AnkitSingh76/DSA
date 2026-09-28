class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!st.empty()){
                st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }    
        stack<char>temp;
        for(int j=0;j<t.size();j++){
            if(t[j]=='#'){
                if(!temp.empty()){
                temp.pop();
                }
            }
            else{
                temp.push(t[j]);
            }
        }
            
        return st==temp;
        
    }
};