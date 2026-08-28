class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {

            // If duplicate exists within last k elements
            if (st.count(nums[i]))
                return true;

            st.insert(nums[i]);

            // Keep window size <= k
            if (st.size() > k)
                st.erase(nums[i - k]);
        }

        return false;
    }
};