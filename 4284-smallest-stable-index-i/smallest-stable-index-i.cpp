class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sfx(n);
        int mn =nums.back();
        for (int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            sfx[i]=mn;
        }
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            if((mx-sfx[i]<=k))
            return i;
        }
        return -1;
    }
};