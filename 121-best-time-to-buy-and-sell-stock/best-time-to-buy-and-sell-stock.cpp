class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0 ;
        int minprice = INT_MAX;
        for(int i =0 ;i < prices.size();i++){

            if(prices[i] < minprice) minprice = prices[i];
            
                int cprofit=0;
                cprofit = prices[i] - minprice;
                profit = max(cprofit,profit);

            
        }
        return profit;
    }
};