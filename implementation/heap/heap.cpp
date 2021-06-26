#include<bits/stdc++.h>

using namespace std;

class MinHeap{
private:
    vector<int> arr;
public:
    bool isEmpty(){
        return arr.empty();
    }

    void print_heap(){
        cout<<"Printing min heap"<<endl;
        if(isEmpty()){
        cout<<"Empty heap"<<endl;
        }else{
            for(int i=0;i<arr.size();i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }

    void push(int x){
        arr.push_back(x);
        int ind = arr.size()-1;
        heapify(ind);
    }

    void heapify(int ind){
        int parent_ind = (ind-1)/2;
        if(parent_ind>=0 && arr[parent_ind]>arr[ind]){
            swap(arr[parent_ind],arr[ind]);
            heapify(parent_ind);
        }
    }
};

class MaxHeap{
private:
    vector<int> arr;
public:
    bool isEmpty(){
        return arr.empty();
    }

    void print_heap(){
        cout<<"Printing min heap"<<endl;
        if(isEmpty()){
        cout<<"Empty heap"<<endl;
        }else{
            for(int i=0;i<arr.size();i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }

    void push(int x){
        arr.push_back(x);
        int ind = arr.size()-1;
        heapify(ind);
    }

    void heapify(int ind){
        int parent_ind = (ind-1)/2;
        if(parent_ind>=0 && arr[parent_ind]<arr[ind]){
            swap(arr[parent_ind],arr[ind]);
            heapify(parent_ind);
        }
    }
};

int main(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout); 
    #endif 

    // MinHeap minH;
    // minH.push(5);
    // minH.push(9);
    // minH.push(10);
    // minH.push(1);
    // minH.print_heap();

    MaxHeap maxH;
    maxH.push(5);
    maxH.push(9);
    maxH.push(10);
    maxH.push(1);
    maxH.print_heap();
}   