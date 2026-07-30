class Solution {
public:
    bool solve(int start, string &s, unordered_set<string> &st, vector<int> &dp) {

        if (start == s.size())
            return true;

        if (dp[start] != -1)
            return dp[start];

        string word = "";

        for (int end = start; end < s.size(); end++) {

            word += s[end];

            if (st.count(word)) {
                if (solve(end + 1, s, st, dp))
                    return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};