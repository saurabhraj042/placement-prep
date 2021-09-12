/**
 *      # Abstract classes may or may not contain abstract methods
 * 
 *      # If a class has at least one pure virtual, then the class is abstract.
 * 
 *      # If a class is abstract, it cannot be instantiated.
 * 
 *      # To use an abstract class, you have to inherit it from another class, 
 *        provide implementations for the abstract methods in it.
 * */

// A virtual Function is a do nothing function without definition.

#include<bits/stdc++.h>

using namespace std;

class AbstractClass {
    public :
        
        // A virtual fun() with no definition.
        virtual void PureVirtualFun () = 0;
        
        void DummyFun () {
            // This fun() is also not usable since this whole class is abstract
        }
};

class ChildOfAbstractClass : public AbstractClass {
    public :
        // Overriding abstract function to make it usable by objects.
        void PureVirtualFun () {
            cout << "Definition is added to Abstract Function in Child Class of Abstract Class" << endl;
        }
}

int main () {
    // Why we make a abstract fun a virtual one ?
    AbstractClass *pointer;
    ChildOfAbstractClass childObject;

    pointer = &childObject;
    // Since this base class pointer can access the Abstract fun of Parent class
    // Which should not be ideally legal, But due to early binding in C++ users
    // could do such thing. So to simply avoid this conflict we make an Abstract 
    // fun a virtual one. Now even if User access it through Base Class Pointer 
    // compiler chooses the Child Class Overrided function.
}