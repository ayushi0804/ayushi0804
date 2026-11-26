
class Solution {
public:
    vector<string> ans;

    void solve(string &num, int target, int idx, long long value,
               long long prev, string path) {

        if (idx == num.size()) {
            if (value == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i != idx && num[idx] == '0') break;

            string s = num.substr(idx, i - idx + 1);
            long long curr = stoll(s);

            if (idx == 0) {
                solve(num, target, i + 1, curr, curr, s);
            }
            else {
                solve(num, target, i + 1,
                      value + curr, curr, path + "+" + s);

                solve(num, target, i + 1,
                      value - curr, -curr, path + "-" + s);

                solve(num, target, i + 1,
                      value - prev + prev * curr,
                      prev * curr, path + "*" + s);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};
