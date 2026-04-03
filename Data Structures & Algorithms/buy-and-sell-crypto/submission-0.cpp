class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int maxp = INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min = prices[i];
            }
            if(prices[i]-min>maxp){
                maxp = prices[i]-min;
            }
        }
        return maxp;
    }
};
