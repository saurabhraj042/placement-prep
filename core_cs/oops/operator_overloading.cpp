/**
 *    # Operator overloading is a way to assign special definition to operators in C++
 *      for user defined / non primitive data types.
 * 
 *    # By Operator overloading Compile time Polymorphism is achieved. 
 * 
 *    # There are certain operators in C++ which cannot be overloaded thos are "::", "? :"
 *      "sizeof()", ".", "*".
 *      
 *    # Friend Functions can also be used to Overload Certain Operators.
 * 
 *    # Binary operators takes an arguements while being overloaded while unary operators takes
 *      none.
 * */
#include<bits/stdc++.h>

using namespace std;

class ComplexNumber {
    private :
        
        int real_part;
        int imag_part;
    
    public :

        ComplexNumber () {
            this->real_part = 0;
            this->imag_part = 0;
        }

        ComplexNumber (int real_part, int imag_part) {
            this->real_part = real_part;
            this->imag_part = imag_part;
        }

        void ShowNumber () {
            cout << real_part <<" + " << imag_part << "i" << endl;
        }

        // Overloading + operator
        ComplexNumber operator+ (ComplexNumber given_number) {
            ComplexNumber new_number;
            
            new_number.real_part = given_number.real_part + real_part;
            new_number.imag_part = given_number.imag_part + imag_part;
            
            return new_number;
        }

        // Overloading ++ operator
        void operator ++ () {
            real_part = real_part + 1;
            imag_part = imag_part + 1;
        }
};

int main () {
    ComplexNumber sample1 (3 , 4);
    ComplexNumber sample2 (5 , 4);
    ComplexNumber sample3;
    
    sample3 = sample1 + sample2;
    ++sample3;
    sample3.ShowNumber();
}