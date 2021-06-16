#include<bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
};

class BST{
private:
    node* root;
public:

    // Constructors
    BST(){
        root = NULL;
    };

    BST(int x){
        root = newNode(x);
    }

    // Check if BST is empty
    bool isEmpty(){
        if( root==NULL ){
            return true;
        }
        return false;
    }

    //
    
    // Create new node
    node* newNode(int x){
        node* p = new node();
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    // Insert new node
    void insert(int x){
        if( isEmpty() ){
            this->root = newNode(x);
            return;
        }

        node* p = root;

        while(1){

            if( x<=p->data && p->left!=NULL ) p = p->left;
            else if( x>p->data && p->right!=NULL) p = p->right;
            else break;
        }

        if( x<=p->data ) p->left = newNode(x);
        else p->right = newNode(x);
       
    }

    // Get the root 
    node* getRoot(){
        return root;
    }
    
    // Function to find height of the BST
    int getHeight(node* p){
        if( p==NULL ) return 0;

        int leftH = getHeight( p->left );
        int rightH = getHeight( p->right );

        return max( leftH+1,rightH+1 ); 
    }

    // Level Order Traversal in O(N^2) without using Queue
    void loTrav(){
        int height = getHeight(root);
        
        cout<<"Level Order traversal of BST in O(N^2) time"<<endl;
        for(int i=1;i<=height;i++){
            printCurrentLevelLOT(root,i);
        }

    }
    void printCurrentLevelLOT(node* p,int level){
        if( p==NULL ) return;
        else if( level==1 ) cout<<p->data<<" ";
        else{
            printCurrentLevelLOT(p->left,level-1);
            printCurrentLevelLOT(p->right,level-1);
        }
    }

    // Level order Traversal in O(N) time and O(N) space using queue
    void loTravQ(){
        queue<node*> q;
        q.push(root);

        cout<<"Level Order traversal of BST in O(N) time"<<endl;
        while( !q.empty() ){
            node * currentNode = q.front();
            q.pop();
            if( currentNode!=NULL ){
                cout<<currentNode->data<<" ";
                q.push( currentNode->left );
                q.push( currentNode->right );
            }
        }
        cout<<endl;
    }
};

int main(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout); 
    #endif 

    BST obj;
    obj.insert(5);
    obj.insert(1);
    obj.insert(6);
    obj.insert(0);
    obj.insert(3);
    obj.loTravQ();
    cout<<obj.getHeight( obj.getRoot() )<<endl;

   
}   