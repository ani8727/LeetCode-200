// 42. Trapping Rain Water

#include <iostream>
#include <vector>
using namespace std;

// 1. brute force appraoch
// int trapWater(vector<int> heights){
//     int n=heights.size();
//     int maxWater=0;

//     for(int i=0;i<n;i++){
//         int leftMax=0, rightMax=0;
        
//         // find left max boundary
//         for(int j=i;j>=0;j--){ // left side
//             leftMax=max(leftMax,heights[j]);
//         }
//         // find right max boundary 
//         for(int j=i;j<n;j++){ // right side
//             rightMax=max(rightMax,heights[j]);
//         }

//         int water=min(leftMax,rightMax)-heights[i];

//         maxWater+=water;
//     }
//     return maxWater;
// }

// 2. better appraoch - prefix and Suffix -> tc:O(n), sc:O(n)
// int trapWater(vector<int> heights){
//     int n=heights.size();

//     vector<int> left(n), right(n);

//     //for left boundary
//     left[0]=heights[0];
//     for(int i=1;i<n;i++){
//         left[i]=max(left[i-1],heights[i]);
//     }
    
//     // for right boundary
//     right[n-1]=heights[n-1];
//     for(int i=n-2;i>=0;i--){
//         right[i]=max(right[i+1],heights[i]);
//     }
//     // water trap calculate
//     int water=0;
//     for(int i=0;i<n;i++){
//         water+=min(left[i],right[i])-heights[i];
//     }

//     return water;
// }

// 3. optimal appraoch- using two pointer;

int trapWater(vector<int> heights){
    int n=heights.size();

    int left=0, right=n-1, water=0;
    int leftMax=0, rightMax=0;

    while(left<=right){
        if(heights[left]<=heights[right]){
            if(heights[left]>=leftMax){
                leftMax=heights[left];
            }else{
                water+=leftMax-heights[left];
            }
            left++;
        }else{
            if(heights[right]>=rightMax){
                rightMax=heights[right];
            }else{
                water+=rightMax-heights[right];
            }
            right--;
        }
    }
    return water;
}
int main()
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Madximum water store: " << trapWater(heights) << endl;

    return 0;
}