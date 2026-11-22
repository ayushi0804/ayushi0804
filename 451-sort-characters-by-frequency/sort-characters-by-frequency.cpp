
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> arr(freq.begin(), freq.end());

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans = "";

        for (auto &p : arr) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};
