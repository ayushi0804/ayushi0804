class Solution {
public:

    int findmax(vector<int>& piles) {
        int maxi = INT_MIN;

        for(int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }

    long long totalhr(vector<int>& piles, int h) {
        long long totalHr = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalHr += (piles[i] + (long long)h - 1) / h;
        }

        return totalHr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = findmax(piles);
        int ans = INT_MAX;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            long long totalHr = totalhr(piles, mid);

            if(totalHr <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};