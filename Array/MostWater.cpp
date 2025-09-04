#include<iostream>
#include<vector>
using namespace std;


//1. Brute force appraoch  - TLE problem in this appraoch
// int mostWater(vector<int> heights){
//     int n=heights.size();
//    int maxArea=0;
//     for(int i=0;i<n-1;i++){
//         int width=1;
//         for(int j=i+1;j<n;j++){
//             int height=min(heights[i],heights[j]);
//             int area=height*width;
//             maxArea=max(area,maxArea);
//             width++;
//         }
//     }
//     return maxArea;
// }

// 2.optimal appraoch - two pointer
int mostWater(vector<int> heights){
    int n=heights.size();

    int left=0;
    int right=n-1;
    int maxArea=0;

    while(left<right){
        int h=min(heights[left],heights[right]);
        int w=right-left;
        int area=w*h;
        maxArea=max(maxArea,area);
        if(heights[left]>heights[right]) right--;
        else left++;
    }
    return maxArea;
}
int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};

    cout<<"Most water Area: "<<mostWater(height)<<endl;

    return 0;
}