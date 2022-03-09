#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printSolution(vector<int>board[],int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<board[i][j];
        cout<<"\n";
    }
}
bool isSafe(vector<int>arr[],int n,int row,int col){
    //to check left row
    for(int i=0;i<col;i++){
        if(arr[row][i]==1){
            return false;
        }
    }
    //Upper left Diagonal
    int i,j;
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    //To check down laft diagonal
    for(i=row,j=col;i<n && j>=0;i++,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    return true;
}
bool addQuens(vector<int> arr[],int n,int col){
    if(col>=n){ 
        return true;
    }
    for(int i=0;i<n;i++){
        
        if(isSafe(arr,n,i,col)){
            arr[i][col]=1;
            if(addQuens(arr,n,col+1)){
                return true;
            }
            arr[i][col]=0;
        }
        
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i].push_back(0);
        }
    }
    
    if(addQuens(arr,n,0)){//start with zeroth coloumn
        
    }
    printSolution(arr,n);
    
}
