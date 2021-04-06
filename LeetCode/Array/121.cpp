//Best Time To buy and Sell Stock
#include "Helper.h"

int maxProfit( vector<int>& prices )
{
#if define OLD_IMPLEMENTATION
        int profit = 0;
        //BruteForce
        for ( int i = 0; i < prices.size(); ++i ) //Runtime 176 ms, Time Complexity - O(n^2), Space Complexity - O(1)
        {
            for ( int j = i + 1; j < prices.size(); ++j )
            {
                int value;
                if ( prices[i] >= prices[j] )
                    break;
                else
                    value = prices[j] - prices[i];

                profit = profit < value ? value : profit;
            }
        }
        return profit;
#elif NEW_IMPLEMENTATION //Runtime 176ms, TC - O(n), SC - O(1)

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for ( int i = 0; i < prices.size(); ++i )
    {
        if ( prices[i] < minPrice )
            minPrice = prices[i];
        else if ( (prices[i] - minPrice) > maxProfit )
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
#endif
}
