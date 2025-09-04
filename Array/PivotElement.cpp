#include<iostream>
#include<vector>
using namespace std;

// find pivot element - smallest number in sorted rotated array

int pivot(vector<int> nums){
    int n=nums.size();
    int st=0;
    int end=n-1;
    while(st<end){
        int mid=st+(end-st)/2;
        if(nums[mid]>=nums[0]){ // means ans in sorted right side array
            st=mid+1;
        }else{
            end=mid;  // means inleft side present
        }
    }
    return end;     // index of lowest element
}
int main(){
    vector<int> nums={5,6,0,1,2,3,4};

    cout<<"pivot: "<<pivot(nums)<<endl;
    return 0;
}
