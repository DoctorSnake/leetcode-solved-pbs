
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int profit = 0;
    int buy_index = -1; // not reached an index on which to buy stocks 
    
    for(int j = 0; j < prices.size()-1; j++){
        if(prices[j+1] - prices[j] > 0) {
            if(buy_index == -1){
                buy_index = j;
            }
        }
        else if (prices[j+1] - prices[j] < 0){
            if(buy_index != -1){ 
                // stocks were bought, need to sell them
                profit += prices[j] - prices[buy_index];
                buy_index = -1;
            }
        }
    }
    if(buy_index != -1){
        profit += prices[prices.size()-1] - prices[buy_index];
    }
    return profit;
}
