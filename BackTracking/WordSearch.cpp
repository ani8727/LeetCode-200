//  79. Word Search

#include<iostream>
#include<vector>
using namespace std;

// global variable
int m,n,l; // size of row, column, word

// store direction  - global variable
vector<pair<int, int>> direction{
    {-1,0},   //top
    {1,0},   //bottom
    {0,-1}, // left
    {0,1}  // right
};

// call recusion for backtracking
bool find(vector<vector<char>>& board, int i, int j, int idx, string& word){

    if(idx==l) // means all char are found
      return true;
    
    if(i<0 || i>=m || j<0 || j>=n) // means bound check for top, bottom, left, right neighbors
       return false;

    if(board[i][j]=='$') // alredy visited before
      return false;

    if(board[i][j]!=word[idx]) // means current char inside board not match to word
      return false;
      
    // if all above condtion not match , we found right char
    char curr=board[i][j]; // store if not ture then store and backtrack them
    board[i][j]='$'; //mark visited

    // check curr all neighbor node using direction
    for(pair<int, int> x_y: direction){
        int new_i = i + x_y.first; 
        int new_j = j + x_y.second;

        if(find(board, new_i, new_j, idx + 1, word)) {
            board[i][j] = curr; // backtrack
            return true;
        }
    }
    board[i][j] = curr; // backtrack
    return false;
}

bool exist(vector<vector<char>>& board, string& word){
    m=board.size(); // column size;
    n=board[0].size(); // row size
    l=word.length(); // string size

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                // if match                 and true
            if(board[i][j]==word[0] && find(board,i,j,0,word))  
                return true; 
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word="ABCCED";

    if(exist(board,word))
       cout<<"Word exist inside Board"<<endl;
    else
      cout<<"Not Exist Word inside Board"<<endl;  

    return 0;
}