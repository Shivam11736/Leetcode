class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int steps = 1;
        while (!q.empty()) {
            for (int i = q.size(); i--; ) {
                auto w = q.front(); q.pop();
                if (w == endWord) return steps;
                dict.erase(w);
                for (int j = 0; j < w.size(); ++j) {
                    char c = w[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        w[j] = ch;
                        if (dict.count(w)) q.push(w);
                    }
                    w[j] = c;
                }
            }
            ++steps;
        }
        return 0;
    }
};
