#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1. brute force appraoch - n3
// vector<vector<int>> threeSum(vector<int> nums, int target){
//     int n=nums.size();
//     sort(nums.begin(),nums.end());

//     vector<vector<int>> ans;

//     for(int i=0;i<n-2;i++){
//         if(i>0 && nums[i]==nums[i-1]) continue;
//         for(int j=i+1;j<n-1;j++){
//             if(j>i+1 && nums[j]==nums[j-1])  continue;
//             for(int k=j+1;k<n;k++){
//                 if(k>j+1 && nums[k]==nums[k-1]) continue;
//                 if(nums[i]+nums[j]+nums[k] == target){
//                    ans.push_back({nums[i],nums[j],nums[k]});
//                 }
//             }
//         }
//     }
//     return ans;
// }

// 2. using two pointer

vector<vector<int>> threeSum(vector<int> nums, int target){
    int n=nums.size();
    sort(nums.begin(),nums.end());

    vector<vector<int>> ans;

    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;

        int left=i+1, right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right]+nums[i];

            if(sum<target) left++;
            else if(sum>target) right--;
            else{
                ans.push_back({nums[i],nums[left],nums[right]});
                while(left<right && nums[left]==nums[left+1]) left++;
                while(right>left && nums[right]==nums[right-1]) right--;
                
                left++; right--;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> nums={-1,0,1,2,-1,-4};

    vector<vector<int>> ans=threeSum(nums,0);

    for(auto num: ans){
        cout<<" [";
        for(int i: num){
            cout<<i<<" ";
        }
        cout<<"] ";
    }

    return 0;
}