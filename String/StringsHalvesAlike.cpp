// 1704. Determine if String Halves Are Alike

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// using hashing  set
bool halvesAlike(string s){
    int n=s.length(); // string length even

    //for vowels
   unordered_set<char> vowels={'a','A','e','E','i','I','o','O','u','U'};
  
    int count=0;
    //first half
    for(int i=0;i<n/2;i++){
        if(vowels.find(s[i])!=vowels.end()) count++;
    }
    //second half
    for(int i=n/2;i<n;i++){
        if(vowels.count(s[i])==1) count--;
    }
    return count==0;    
}

// using vector
// bool halvesAlike(string s){
//     int n=s.length(); // string length even

//     //for vowels
//     vector<int>vowels(26,0);

//     vowels['a'-'a']=1;
//     vowels['e'-'a']=1;
//     vowels['i'-'a']=1;
//     vowels['o'-'a']=1;
//     vowels['u'-'a']=1;
  
//     int count=0;
//     //first half
//     for(int i=0;i<n/2;i++){
//         if(vowels[tolower(s[i])-'a']==1) count++;
//     }
//     //second half
//     for(int i=n/2;i<n;i++){
//         if(vowels[tolower(s[i])-'a']==1) count--;
//     }
//     return count==0;    
// }

int main(){
    string s;
    cin>>s;

    if(halvesAlike(s)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}