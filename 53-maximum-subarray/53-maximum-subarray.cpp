class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], mx=INT_MIN;
        mx = max(sum, mx);
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]+sum < nums[i])
                sum=nums[i];
            else
                sum+=nums[i];
            mx = max(sum, mx);
        }
        return mx;
    }
};