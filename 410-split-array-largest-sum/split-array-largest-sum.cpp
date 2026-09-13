class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid){
        int n = nums.size();
        int painters = 1, time = 0;
        for(int i = 0; i < n; i++){
            if(time+nums[i] <= mid){
                time += nums[i];
            }else{
                painters++;
                time = nums[i];
            }
        }
        return painters <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, maxVal = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxVal = max(maxVal, nums[i]);
        }
        int st = maxVal, end = sum, ans = -1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(isPossible(nums,k,mid)){
                ans = mid;
                end = mid-1;
            }else st = mid + 1;
        }
        return ans;
    }
};