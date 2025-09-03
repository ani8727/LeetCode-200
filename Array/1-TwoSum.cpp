// 1. two sum ->  three appraoch 

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//1.  Brute force approaoch - n2
// vector<int> twoSum(vector<int> nums,int target){
//     int n=nums.size();
//     for(int i=0;i<n-1;i++){
//        for(int j=i+1;j<n;j++){
//         if(nums[i]+nums[j]==target){
//             return {nums[i],nums[j]}; // if want return indices the  {i,j}
//         }
//        }
//     }
//     return {-1,-1};
// }

// 2. sorting and two pointer appraoch
// only for return nums not indices because change original place

// vector<int> twoSum(vector<int> nums, int target){
//     int n=nums.size();
//     sort(nums.begin(),nums.end());
//     int left=0, right=n-1;
//     while(left<right){
//         if(nums[left]+nums[right]>target){
//             right--;
//         }else if(nums[right]+nums[left]<target){
//             left++;
//         }else{
//             return{nums[left],nums[right]};
//         }
//     }
//     return {-1,-1};
// }

// 3. optimal appraoch using unordered map

vector<int> twoSum(vector<int> nums,int target){
     unordered_map<int, int> mp;

     for(int i=0;i<nums.size();i++){

        int complement = target-nums[i];

        if(mp.count(complement)){
            return {nums[mp[complement]],nums[i]};  // if want to retrurn value
            // return {mp[complement],i}; // if index retrun 
        }
        mp[nums[i]]=i;
     }
     return {-1,-1};
}
int main(){
    vector<int> nums={2,7,11,15};

    vector<int> ans=twoSum(nums,9);

    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;

}