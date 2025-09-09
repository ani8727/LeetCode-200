// 1662. Check If Two String Arrays are Equivalent

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

// brute force appraoch - concanate karna 
// bool equivalent(vector<string> word1, vector<string> word2){
//     string s1="";
//     for(string st: word1){
//         s1+=st;
//     }
//     string s2="";
//     s2=accumulate(word2.begin(),word2.end(),string(""));
    
//     if(s1==s2){
//         return true;
//     }
//     return false;
// }

// optimal appraoch
bool equivalent(vector<string> word1, vector<string> word2){
    int n=word1.size();
    int m=word2.size();
    
    int w1=0, w2=0; // word string inside vector for w1, w2
    int i=0, j=0;  // index for for word char

    while(w1<n && w2<m){
        if(word1[w1][i]!=word2[w2][j]){
            return false;
        }
        i++;
        j++;
        if(w1<n && i==word1[w1].length()){  // if word1 vector string end, for moving next string
            i=0;
            w1++;
        }
        if(w2<m && j==word2[w2].length()){
            j=0;
            w2++;
        }
    }
    return (w1==n && w2==m); // means all char traverse if not it return false;
}

int main(){
    vector<string> word1={"a","bc","d"};
    vector<string> word2={"ab","cd","e"};

    if(equivalent(word1,word2)){
        cout<<"Equivalnet two String Array";
    }else{
        cout<<"Not Equivalent";
    }
    return 0;
}