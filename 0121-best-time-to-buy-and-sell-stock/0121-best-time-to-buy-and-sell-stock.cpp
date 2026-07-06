class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int mini=prices[0];
         for(int i=1;i<prices.size();i++){ 
            int cost=prices[i]-mini;
            max_profit=max(max_profit,cost);
            mini=min(mini,prices[i]);
         }
         return max_profit;
    }
};