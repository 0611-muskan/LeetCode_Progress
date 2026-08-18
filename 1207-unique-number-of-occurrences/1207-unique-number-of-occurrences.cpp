class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int num : arr) {
            mp[num]++;
        }

        // Store frequencies
        unordered_set<int> st;

        for (auto it : mp) {
            if (st.count(it.second))
                return false;

            st.insert(it.second);
        }

        return true;
    }
};