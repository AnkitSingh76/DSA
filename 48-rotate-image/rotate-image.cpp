class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int>ans;
        int i,j,n =matrix.size(),col=matrix[0].size();
        
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(i=0;i<n;i++){
        int start=0,end=n-1;
        while(start<end){
            swap(matrix[i][start],matrix[i][end]);
            start++;
            end--;
        }

        }

    }
};