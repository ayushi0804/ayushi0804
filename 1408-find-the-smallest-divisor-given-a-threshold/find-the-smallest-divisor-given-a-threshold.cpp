class Solution {
public:
    int sum(vector<int>& nums, int threshold){
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum = sum + ceil((double)(nums[i])/(double)(threshold));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold) return -1;
        int l = 1, h = *max_element(nums.begin(), nums.end());
        while(l <= h){
            int mid = l + (h-l)/2;
            if(sum(nums,mid) <= threshold) h = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};