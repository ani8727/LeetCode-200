// 53. Maximum Subarray - Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include<iostream>
#include<vector>
using namespace std;



// 1. Brute force approach
// int maximumSum(vector<int> nums){  
//     int n=nums.size();
//     int maxSum=0;
//     for(int st=0;st<n;st++){
//         int currSum=0;
//         for(int end=st;end<n;end++){
//             currSum+=nums[end];
//             maxSum=max(maxSum,currSum);
//         }
//     }
//     return maxSum;
// }

//2. kadane algorithm

int maximumSum(vector<int> nums){
    int n=nums.size();
    int currSum=0, maxSum=0;

    for(int i=0;i<n;i++){
        currSum+=nums[i];
        maxSum=max(maxSum,currSum);
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};

    cout<<"Max Sum Subarray: "<<maximumSum(nums)<<endl;

    return 0;
}