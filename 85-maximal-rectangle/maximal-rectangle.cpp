class Solution {
public:

    int lHist(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++) {

            while(!st.empty() &&
                  (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;

        vector<vector<int>> psum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {

            int sum = 0;

            for(int i = 0; i < n; i++) {

                if(matrix[i][j] == '1')
                    sum += 1;
                else
                    sum = 0;

                psum[i][j] = sum;
            }
        }

        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, lHist(psum[i]));
        }

        return maxArea;
    }
};