#include<bits/stdc++.h>

using namespace std;

// When final specifier is added to any function they cannot be overriden or if added
// to any struct or class they cannot be inherited.

// final SPECIFIER use
class A {
    public:
        virtual void FunA () final {
            // This function cannot be OVERRRIDEN cause of final specifier.
        }
};

class B final {
    // This class cannot be inherited in any case
}

struct C final {
    // This struct cannot be inherited.
}