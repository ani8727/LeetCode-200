// 217. Contains Duplicate - Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// 1. brute force appraoch - n2
// bool find(vector<int> nums){
//     int n=nums.size();
//     for(int i=0; i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(nums[i]==nums[j])
//                 return true;
//         }
//     }
//     return false;
// }


//2. optimal appraoch - unorderedmap

bool find(vector<int> nums){
    unordered_set<int> s;

    for(int val: nums){
        if(s.count(val)){
            return true;
        }
        s.insert(val);
    }
    return false;
}


int main(){
    vector<int> nums{1,2,3,4,5};

    if(find(nums)) cout<<"Contains duplicate"<<endl;
    else cout<<"Not conatins dupllcate"<<endl;

    return 0;
}
