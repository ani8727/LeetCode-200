// 242. Valid Anagram

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;


//1. brute force appraoch - using sorting
// bool validAnagram(string s, string t){
//     if(s.length()!=t.length()) return false;

//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());

//     if(s==t) return true;
//     else   return false;
// }

//2. better apprach - using map
// bool validAnagram(string s, string t){
//     unordered_map<char, int> mp;

//     for(char ch:s){ // inseting all char through s
//         mp[ch]++;
//     }
//     for(char ch: t){ // removing all char through t
//         if(!mp.count(ch) || mp[ch]==0){
//             return false;
//         }
//         mp[ch]--;
//     }
//     return true;
// }

// 3. optimal approach- using constant vector for string
bool validAnagram(string s, string t){
    vector<int> count(26,0);

    for(char ch: s){
        count[ch-'a']++; // updating index value char
    }
    for(char ch: t){
        count[ch-'a']--;  // removing char using t
    }
    // if at any index value not 0 means not anagram
    bool all_Zero=all_of(begin(count), end(count), [](int element){
        return element==0;
    });

    return all_Zero;
}

int main(){
    string s="anagram";
    string t="agraman";

    if(validAnagram(s,t)){
        cout<<"Valid Anagram";
    }else{
        cout<<"Not valid Anagram";
    }
    return 0;
}