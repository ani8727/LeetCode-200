// 121. Best Time to Buy and Sell Stock

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// 1. simple appraoch
// int maxProfit(vector<int> prices){
//     int n=prices.size();
//     int minCost=INT_MAX;
//     int maxPro=0;

//     for(int i=0;i<n;i++){
//         if(minCost>prices[i]){
//             minCost=prices[i];
//         }
//         if(maxPro<prices[i]-minCost){
//             maxPro=prices[i]-minCost;
//         }
//     }
//     return maxPro;
// }

// 2. consise way

int maxProfit(vector<int> prices){
    int minCost=INT_MAX;
    int maxPro=0;

    for(int price: prices){
        minCost=min(minCost,price);
        maxPro=max(maxPro,price-minCost);
    }
    return maxPro;
}

int main(){
    vector<int> prices={7,6,4,3,1};

    cout<<"Max profit : "<<maxProfit(prices)<<endl;

    return 0;
}