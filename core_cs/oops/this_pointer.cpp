/**
 *      # 'This' keyword is a OBJECT POINTER present inside the INSTANCE_MEMBER FUNCTION
 *         block of a CLASS and it stores the ADDRESS of CALLER OBJECT.
 *      
 *      # It's value cannot be modified.
 * 
 *      # USES :
 *          -> used to refer current class instance variable / When local variable’s name is same as member’s name
 *          -> To return reference to the calling object
 *          -> To pass refrence of itself as an arguement
 * */
 #include<bits/stdc++.h>

 using namespace std;

 class Demo {
    private :
        
        Demo* caller_ob_ref;
        Demo* other_ob_ref;
    
    public :
        
        Demo () {
            caller_ob_ref = this;
            other_ob_ref = NULL;
        }

        // Refrencing current object reference
        Demo* GetObjRef () {
            // this object pointer stores add of caller object
            return this;
        }

        void RecObjRef (Demo* other_ob_ref) {
            this->other_ob_ref = other_ob_ref;
        }

        void ShowValues () {
            cout << "Caller Object Add :" << caller_ob_ref << endl;
            cout << "Other Object Add :" << other_ob_ref << endl;
        }
 };

 int main () {
     Demo objectA;
     objectA.ShowValues();
     cout << endl;

     Demo objectB;
     objectA.RecObjRef(&objectB);
     objectA.ShowValues();
 }