class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count =0;
        int n=word.length();
        for(int i=0;i<patterns.size();++i){
            int m=patterns[i].length();

            for(int j=0;j+m<=n;++j){
                bool found =true;
                for(int k=j;k<j+m;++k){
                    if(word[k]!=patterns[i][k-j]){
                        found =false;
                        break;
                    }
                }
                if(found){
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};