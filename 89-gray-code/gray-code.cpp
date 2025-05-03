class Solution {
public:
    vector<int> grayCode(int n) {
        int start = 0;
        int end = pow(2, n); // Generate up to 2^n 

        vector<int> ans;
        for (int i = start; i < end; ++i) {
            int gray = i ^ (i >> 1); // Gray code formula
            ans.push_back(gray);
        }

        return ans;
    }

};