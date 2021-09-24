#include<bits/stdc++.h>

using namespace std;

int arr[1000002];
int top = -1;

void push (int x) {
    if (x >= 1e6) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    arr[top] = x;
}

void get_top () {
    cout << arr[top] << endl;
}

void pop () {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return;
    }
    top--;
}

int main () {
    push (6);
    get_top();
    push(5);
    get_top();
    pop();
    get_top();
}