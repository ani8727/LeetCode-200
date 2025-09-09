// 12. Integer to Roman

#include<iostream>
#include<vector>
using namespace std;

string convert(int nums){
    vector<pair<int, string>> roman = {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
        {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},
        {5,"V"},{4,"IV"},{1,"I"}
    };
    string ans="";
    for(auto &i: roman){
        int value=i.first;
        string key=i.second;
        int times=0;
        if(nums>=value){
            times=nums/value;
            nums=nums%value;
            for(int i=1;i<=times;i++){
                ans+=key;
            }
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