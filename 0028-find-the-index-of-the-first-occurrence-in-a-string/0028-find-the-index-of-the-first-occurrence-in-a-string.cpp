class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int start = 0; start <= n - m; start++) {
            int i = start;
            int j = 0;

            while (j < m && haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m)
                return start;
        }

        return -1;
    }
};