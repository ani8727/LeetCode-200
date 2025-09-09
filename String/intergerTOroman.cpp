// 12. Integer to Roman

#include<iostream>
#include<vector>
using namespace std;

// 1. brute force apprach
// string convert(int nums){
//     vector<pair<int, string>> roman = {
//         {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
//         {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},
//         {5,"V"},{4,"IV"},{1,"I"}
//     };
//     if(nums<=0) return "";
//     string ans="";
//     for(auto &i: roman){
//         if(nums==0) break;
//         int value=i.first;
//         string key=i.second;
//         int times=0;
//         if(nums>=value){
//             times=nums/value;
//             nums=nums%value;
//             for(int i=1;i<=times;i++){
//                 ans+=key;
//             }
//         }
//     }
//     return ans;
// }

//2. apprach optimal
// string convert(int nums){
//     vector<pair<int, string>> roman = {
//         {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
//         {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},
//         {5,"V"},{4,"IV"},{1,"I"}
//     };
//     if(nums<=0) return "";
//     string ans="";
//     for(auto &i: roman){
//         if(nums==0) break;
//         int value=i.first;
//         string key=i.second;
//         int times=nums/value; //if times>0 means val<nums and we have to add some key
//         nums=nums%value;  // reduce the wether add string or not
//         for(int i=1;i<=times;i++){
//             ans+=key;
//         }
//     }
//     return ans;
// }

//3. better appraoch - more iterative
string convert(int nums){
    vector<pair<int, string>> roman = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
        {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},
        {5,"V"},{4,"IV"},{1,"I"}
    };
    if(nums<=0) return "";
    string ans="";
    for(auto &i: roman){
        if(nums==0) break;
        int value=i.first;
        string key=i.second;
       while(nums>=value){
        ans+=key;
        nums-=value;
       }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

   cout<< convert(n)<<endl;

   return 0;
}