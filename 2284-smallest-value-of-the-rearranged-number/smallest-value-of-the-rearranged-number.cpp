class Solution {
public:
    long long smallestNumber(long long num) {
        if (!num) return num;
        bool neg = num < 0;
        string s = to_string(neg ? -num : num);
        if (neg) {
            sort(s.begin(), s.end(), greater<char>());
            return -stoll(s);
        } 
        else {
            sort(s.begin(), s.end());
            if (s[0] == '0') {
                for (int i = 1; i < s.length(); ++i) {
                    if (s[i] != '0') {
                        swap(s[0], s[i]);
                        break;
                    }
                }
            }
            return stoll(s);
        }
    }
};