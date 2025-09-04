// 33. Search in Rotated Sorted Array

#include<iostream>
#include<vector>
using namespace std;

// pivot element find
// int pivot(vector<int> nums, int n){
//     int st=0;
//     int end=n-1;
//     while(st<end){
//         int mid=st+(end-st)/2;
//         if(nums[mid]>=nums[0]){
//             st=mid+1;
//         }else{
//             end=mid;
//         }
//     }
//     return end;
// }
// // binary search two parts
// int binary(vector<int> nums, int st, int end, int target){
//     while(st<=end){
//         int mid=st+(end-st)/2;
//         if(nums[mid]>target) end=mid-1;
//         else if(nums[mid]<target) st=mid+1;
//         else return mid;
//     }
//     return -1;
// }
// int search(vector<int> nums,int target){
//       int n=nums.size();
//       int pivotEle=pivot(nums,n);

//       if(target>=nums[pivotEle] && target<=nums[n-1]){
//         return binary(nums,pivotEle,n-1,target);
//       }else {
//         return binary(nums,0,pivotEle-1,target);
//       }
// }

// 2. appraoch

int search(vector<int> nums, int target){
    int n=nums.size();
    int st=0, end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;

        if(nums[mid]==target) return mid;

        if(nums[mid]>=nums[st]){
            if(target>=nums[st] && target<nums[mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else{
            if(target>nums[mid] && target<=nums[end]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums={4,5,6,7,0,2,3};

    cout<<"Element present at : "<<search(nums,2)<<endl;

    return 0;
}