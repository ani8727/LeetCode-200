// 56. Merge Intervals

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1. brute force appraoch
// vector<vector<int>> merge(vector<vector<int>> nums){
//     sort(nums.begin(),nums.end());
//     int n=nums.size();

//     vector<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         int st=nums[i][0];
//         int end=nums[i][1];

//         if(!ans.empty() && ans.back()[1]>=end) continue;

//         for(int j=i+1; j<n;j++){
//             if(nums[j][0] <= end){
//                 end=max(end,nums[j][1]);
//             }
//             else{
//                 break;
//             }
//         }
//         ans.push_back({st,end});
//     }
//     return ans;
// }


// 2. optimal appraoch

vector<vector<int>> merge(vector<vector<int>> nums){
    sort(nums.begin(),nums.end());
    int n=nums.size();

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        // if empty ya interval overlap nhi kar rha
        if(ans.empty() || ans.back()[1]<nums[i][0]){
            ans.push_back(nums[i]);  // direct those interval push
        }
        // if overlap kar rhe ho to direct uske last index par ja ke change karna
        else{
            ans.back()[1]=max(ans.back()[1],nums[i][1]);
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> nums={{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans=merge(nums);

    for(auto num: ans){
        cout<<"[ ";
        for(int i: num){
            cout<<i<<" ";
        }cout<<"] ";
    }
    return 0;
}