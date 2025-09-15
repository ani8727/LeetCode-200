#include<iostream>
#include<algorithm>
using namespace std;

// 1.basic or brute-force Approach

// Rotate manually 
void rotateManually(string &s){
    char first=s[0];
    for(int i=0;i<s.length()-1;i++){
        s[i]=s[i+1];
    }
    s[s.length()-1]=first;
}
//sort manually
void sortManually(string &s){
    int n=s.length();

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(s[j]>s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
string orderly(string s, int k){
    if(k==1){
        string ans=s;
        // for(int i=0;i<s.length();i++){
        //     rotate(s.begin(),s.begin()+1,s.end());
        //     if(s<ans) ans=s;
        // }
                    // do manually rotate
        for(int i=0;i<s.length();i++){
           rotateManually(s);
           if(s<ans) ans=s;
        }          
        return ans;
    }else{
        // sort(s.begin(),s.end());
        sortManually(s);
        return s;
    }
}
int main(){
    string s="baaca";
    int k=3;

    cout<<orderly(s,k)<<endl;
    return 0;
}