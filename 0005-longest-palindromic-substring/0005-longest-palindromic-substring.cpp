class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        vector<vector<bool>>dp(n,vector<bool>(n, false));
        int max_len=1;
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i]==s[j]){
                    if(len<=3)
                        dp[i][j]=true;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]&&len>max_len){
                    max_len=len;
                    start=i;
            }
            }
        }
        return s.substr(start,max_len);
    }
};