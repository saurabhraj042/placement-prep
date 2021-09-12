/**
 *  If derived class defines same function as defined in its base class, 
 *  it is known as function overriding in C++. 
 *  It is used to achieve runtime polymorphism. 
 *  It enables you to provide specific implementation of the function which is already provided by its base class.
 * */
#include<bits/stdc++.h>

using namespace std;

class OldCar {
    public :

        void ShiftGear () {
            cout << "Manual Transmission in Old Cars" << endl;
        }

        virtual void SteeringType () {
            cout << "Bearing Based Steering Wheel in Old Cars" << endl;
        }

        void Radio () {
            cout << "Radio present in Old Cars" << endl;
        }
};

class SportsCar : public OldCar {
    public :
        
        void ShiftGear () {
            cout << "Automatic Transmission in Sports Car" << endl;
        }

        void SteeringType () {
            cout << "Power Steering Wheel in Sports Car" << endl;
        }        
};

int main () {
    SportsCar sportsCar;
    
    cout << "Early Binding demonstration based on caller object type done by compiler" << endl;
    
    sportsCar.SteeringType();
    sportsCar.ShiftGear(); 
    // Compiler looks for ShiftGear() in caller object's class first, if it finds it there then OK
    // Otherwise it will look in Parent class for the same function, just like in the next example

    sportsCar.Radio();
    // Since this method doesn't exist in caller obj's class it looks for it in Parent class.

    cout << endl << "Demonstration of the need for Late Binding" << endl;

    OldCar *pointer;    // Base Class pointer object
    pointer = &sportsCar;   // Holds the address of Child class

    pointer->ShiftGear();   // It selects ShiftGear() from class of pointer object becaus of early binding

    // To fix this issue the compiler needs to look into the type of data who's address is stored in pointer
    // This can be achieved at Runtime only, because only then pointer is assigned its value
    // So we use virtual keyword with overrided functions to let the compiler know that it need to look
    // at it's type during the runtime
    
    cout << endl << "Late Binding demonstration based on type of data held by the base class pointer done by compiler" << endl;

    pointer->SteeringType();
}