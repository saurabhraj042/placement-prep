// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/

#include<bits/stdc++.h>
using namespace std;

void printUtil(vector<vector<string>> &a,int row,int col,vector<string> &out){
    out[row] = a[row][col];

    if(row = size(a) - 1){
        for(int i=0;i<size(a);i++){
            cout<<out[i];
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<size(a[row]);i++){
        if(a[row+1][i] != ""){
            printUtil(a,row+1,i;out);
        }
    }
}

void print(vector<vector<string>> &a){
    int row = size(a);
    
    vector<string> out(row);

    for(int i=0;i<size(a[0]);i++){
        if(a[0][i] != ""){
            printUtil(a,0,i,out);
        }
    }
}

int main(){
    int rows,cols;
    rows = cols = 3;

    vector<vector<string>> a(rows,vector<string>(cols)) = 
        {   {"you", "we"},
            {"have", "are"},
            {"sleep", "eat", "drink"}
        };

    print(a);
}