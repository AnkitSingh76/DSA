class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(),freq;
        int res=0;

        for(int i=0;i<n;i++){
            int len=0;
            int freq=0;

            for(int j=i;j<n;j++){
                len++;
                if(nums[j]==target){
                    freq++;
                }
                if(freq>len/2){
                    res++;
                }
            }
        }
        return res;
    }
};