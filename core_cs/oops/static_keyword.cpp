
#include<bits/stdc++.h>
using namespace std;

/**
 *    # Data members of Class that have 'static' keyword are called Class Members
 * 
 *    # Static members of class can be accessed / called through Objects of Class 
 *      and directly with CLASS_NAME :: MEMBER_NAME as well. So they can be used
 *      even when no Object is created.
 * 
 *    # Static data members need to be defined outside the Class as well, then only
 *      they get memory allocation.
 * 
 *    # Static members get get memory allocation only once and they are present in
 *      memory for the entire lifetime of the program. They are not instantiated
 *      every time new Object is created.
 * 
 *    # They are accessible everywhere by using scope resolution operator with class
 *      name.
 * 
 *   ## Static members has default value of 0;
 * */
class Demo {
    private :
        string instance_member;
        static string class_member;
    public :
        // setClassMember() function can be also called as Class Function
        static void setClassMember () {
            class_member = "Hi I'm a Class Member";
            cout << class_member << endl;
        }
};

// Must do DFINITION of Static Class Members outside the Class
// Now memory is allocated to it
// If we don't provide initial value to it 0 or NUll is assigned to it.
string Demo :: class_member;

/**
 *    # Static local variables inside a function gets memory allocation
 *      at the start of the program and is present for the entire life
 *      -time of the program.
 * */
void DemoFunction () {
    int local_variable;
    static int static_local_variable;
}

// Below program is to show the Lifetime of a static variable
class BurgerShop {
    private :
        static int total_burger_avail;
    public :
        void EatBurger (int quantity) {
            if(quantity > total_burger_avail){
                cout << "Sorry store has no more food. :(" << endl;
                return;
            }

            cout << "Eaten " << quantity << " burgers. :)" << endl;
            
            total_burger_avail -= quantity;
        }

        static void QuanBurgerLeft () {
            cout << "Burget Left :" << total_burger_avail << endl;
        }
};

int BurgerShop :: total_burger_avail = 100;

int main(){
   // Demo :: setClassMember();

   BurgerShop :: QuanBurgerLeft();

   // Rahul enters the shop to eat 10 burgers :O
   BurgerShop Rahul;
   Rahul.EatBurger(10);
   Rahul.QuanBurgerLeft();

   // Now Nakul enters to eat 50 burgers :P
   BurgerShop Nakul;
   Nakul.EatBurger(50);
   Nakul.QuanBurgerLeft();

}