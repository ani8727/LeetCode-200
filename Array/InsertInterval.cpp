//  57. Insert Interval

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// brute force apprach
// vector<vector<int>> insertInterval(vector<vector<int>> intervals, vector<int> newInterval){
//     intervals.push_back(newInterval);  // add in intervals
//     sort(intervals.begin(), intervals.end());
//     int n=intervals.size();

//     vector<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         if(ans.empty() || ans.back()[1]<intervals[i][0]){
//             ans.push_back(intervals[i]);
//         }
//         else{
//             ans.back()[1]=max(ans.back()[1],intervals[i][1]);
//         }
//     }
//     return ans;
// }

//2. optimal approach
vector<vector<int>> insertInterval(vector<vector<int>> intervals, vector<int> newInterval){
// not need sorting ans already sorted form 
    vector<vector<int>> ans;

    int n=intervals.size();
    int i=0;

    // add all interval before new interval like [1,2]-[4,8]
    while(i<n && intervals[i][1]<newInterval[0]){
        ans.push_back(intervals[i]); //[1,2]
        i++;
    }
    // add overlapping interval like [3,5] - [4,8] -> 2nd =[6,7]-[3,8] -> 3rd=[8,10]-[3,8]
    while(i<n && intervals[i][0]<=newInterval[1]){
        newInterval[0]=min(newInterval[0],intervals[i][0]);// 3 ->3 ->3
        newInterval[1]=max(newInterval[1],intervals[i][1]);// 8 ->8 ->10
        i++; //1-2-3
    }//[3,10]
    ans.push_back(newInterval); // [1,2]-[3,10]

    // after new interval jo remaing hai like - [12,16]
    while(i<n){
        ans.push_back(intervals[i]); //[1,2]-[3,10]-[12,16]
        i++;
    }
    return ans;
}

int main(){
   vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
   vector<int> newInterval={4,8};

   vector<vector<int>> nums=insertInterval(intervals, newInterval);
   
   for(vector<int> num:nums){
    cout<<"[";
    for(int i: num){
        cout<<i<<" ";
    }
    cout<<"]";
   }
   
   return 0;

}