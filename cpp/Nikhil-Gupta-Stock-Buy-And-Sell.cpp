//Stock Buy Sell to Maximize Profit
/*
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3. Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

Naive approach: A simple approach is to try buying the stocks and selling them on every single day when profitable and keep updating the maximum profit so far.

#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return the maximum profit 
// that can be made after buying and 
// selling the given stocks 
int maxProfit(int price[], int start, int end) 
{ 
  
    // If the stocks can't be bought 
    if (end <= start) 
        return 0; 
  
    // Initialise the profit 
    int profit = 0; 
  
    // The day at which the stock 
    // must be bought 
    for (int i = start; i < end; i++) { 
  
        // The day at which the 
        // stock must be sold 
        for (int j = i + 1; j <= end; j++) { 
  
            // If byuing the stock at ith day and 
            // selling it at jth day is profitable 
            if (price[j] > price[i]) { 
  
                // Update the current profit 
                int curr_profit = price[j] - price[i] 
                                  + maxProfit(price, start, i - 1) 
                                  + maxProfit(price, j + 1, end); 
  
                // Update the maximum profit so far 
                profit = max(profit, curr_profit); 
            } 
        } 
    } 
    return profit; 
} 
  
// Driver code 
int main() 
{ 
    int price[] = { 100, 180, 260, 310, 
                    40, 535, 695 }; 
    int n = sizeof(price) / sizeof(price[0]); 
  
    cout << maxProfit(price, 0, n - 1); 
  
    return 0; 
} 
*/
/*
Efficient approach: If we are allowed to buy and sell only once, then we can use following algorithm. Maximum difference between two elements. Here we are allowed to buy and sell multiple times.
Following is algorithm for this problem.

Find the local minima and store it as starting index. If not exists, return.
Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
Update the solution (Increment count of buy sell pairs)
Repeat the above steps if end is not reached.
*/
#include <bits/stdc++.h> 
using namespace std; 
  
// This function finds the buy sell 
// schedule for maximum profit 
void stockBuySell(int price[], int n) 
{ 
    // Prices must be given for at least two days 
    if (n == 1) 
        return; 
  
    // Traverse through given price array 
    int i = 0; 
    while (i < n - 1) { 
  
        // Find Local Minima 
        // Note that the limit is (n-2) as we are 
        // comparing present element to the next element 
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; 
  
        // If we reached the end, break 
        // as no further solution possible 
        if (i == n - 1) 
            break; 
  
        // Store the index of minima 
        int buy = i++; 
  
        // Find Local Maxima 
        // Note that the limit is (n-1) as we are 
        // comparing to previous element 
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; 
  
        // Store the index of maxima 
        int sell = i - 1; 
  
        cout << "Buy on day: " << buy 
             << "\t Sell on day: " << sell << endl; 
    } 
} 
  
// Driver code 
int main() 
{ 
    // Stock prices on consecutive days 
    int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
    int n = sizeof(price) / sizeof(price[0]); 
  
    // Fucntion call 
    stockBuySell(price, n); 
  
    return 0; 
} 
/*
Time Complexity: The outer loop runs till i becomes n-1. 
The inner two loops increment value of i in every iteration.
So overall time complexity is O(n)
*/
