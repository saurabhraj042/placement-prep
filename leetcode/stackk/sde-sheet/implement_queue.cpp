#include<bits/stdc++.h>

using namespace std;

int arr[1000];
int front = -1;
int rear = -1;

bool isEmpty(){
    if(front == -1 ||) return true;
    return false;
}

void push(int x){
    if(front == -1) front++;
    rear++;
    arr[rear%1000] = x;
}

void pop(){
    front = (front + 1) % 1000;
}

int main(){
    
}