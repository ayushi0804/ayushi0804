class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0, noofB = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }else{
                noofB += (cnt/k);
                cnt = 0;
            }
        }
        noofB += (cnt/k);
        if(noofB >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        long long val = m * 1ll * k * 1ll;
        if(val > n) return -1;
        int mini = INT_MAX, maxi= INT_MIN;
        for(int i = 0; i < n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi, ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};