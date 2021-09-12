#include<bits/stdc++.h>

using namespace std;

/** Super keyword is basically used to access immediate Parent Class Object.
 *  
 *  Whenever instance of subclass is created, an instance of parent class 
 *  is created implicitly which is referred by super reference variable.
 * 
 *  By using super keyword inside a child class we can call parent class method,
 *  access instance variables and constructor of the same.
 * */

class Base {
    public :
        int instance_var;

        void Method () {
            cout << "Base class function." << endl;
        }
};

class Child : public Base {
    private :
        typedef Base super; 
        // we define super in base class because in C++ the super keyword is not
        // present in the standard library
        
    public :
        void AccessParentClass () {
            super :: Method();
        }
};

int main () {
    Child a;
    a.AccessParentClass();
}
