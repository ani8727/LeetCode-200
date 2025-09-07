//  443. String Compression

#include<iostream>
#include<vector>

using namespace std;

int compressed(vector<char> chars){
    int n=chars.size();

    int i=0;
    int j=0;

    while(i<n){
        char curr=chars[i];
        int count=0;

        while(i<n && chars[i]==curr){
            count++;
            i++;
        }
        chars[j++]=curr;
        if(count>1){
            string s=to_string(count);
            for(char ch: s){
                chars[j++]=ch;
            }
        }
    }
    return j;
}

int main(){
    vector<char> chars={'a','a','b','b','c','c','c'};

    cout<<"Compressed String length: "<<compressed(chars)<<endl;

    return 0;
}