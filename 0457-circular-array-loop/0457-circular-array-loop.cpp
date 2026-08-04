class Solution {
public:

    int nextIndex(vector<int>& nums, int curr, bool forward) {

        bool direction = nums[curr] > 0;

        if (direction != forward)
            return -1;

        int n = nums.size();

        int next = ((curr + nums[curr]) % n + n) % n;

        if (next == curr)
            return -1;

        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                slow = nextIndex(nums, slow, forward);

                if (slow == -1)
                    break;

                fast = nextIndex(nums, fast, forward);

                if (fast == -1)
                    break;

                fast = nextIndex(nums, fast, forward);

                if (fast == -1)
                    break;

                if (slow == fast)
                    return true;
            }
        }

        return false;
    }
};