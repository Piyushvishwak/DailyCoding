// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isSafe(char board[][100],int n,int row,int col){
    //check col
    for(int r=0;r<=row;r++){
        if(board[r][col]=='Q'){
            return false;
        }
    }
    
    //check diagonals
    int x,y;
    x = row,y=col;
    while(x>=0 && y>=0){
        if(board[x][y]=='Q'){
            return false;
        }
        x--;
        y--;
    }
    
    x = row,y=col;
    while(x>=0 && y<=n-1){
        if(board[x][y]=='Q'){
            return false;
        }
        x--;
        y++;
    }
    
    return true;
}

// only one config
int generateNQueenConfigs(int N,char board[][100],int row, int &count){
    //base case 
    if(row==N){
        count++;
        //Print the board & return 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return count;
    }
    
    // rec case 
    // Try every col in current row to place a queen
    for(int col=0;col<N;col++){
        if(isSafe(board,N,row,col)){
            board[row][col] = 'Q';
            generateNQueenConfigs(N,board,row+1,count);
            
            //backtrack
            board[row][col] = '_';
        }
    }
    return count;
}

int main() {
    // Write C++ code here
    int n = 4;
    
    //init the board
    int count=0;
    char board[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = '_';
        }
    }
    
    cout<<generateNQueenConfigs(n,board,0,count);
    
    
    return 0;
}