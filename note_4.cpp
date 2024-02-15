#include <iostream>

using namespace std;

class C {
private:
    int a = 0;
    int b = 0;
public:
    int f() const {
        C* p = const_cast<C*>(this);
        p->a = 1;
        return this->a;
    }
};

struct D {
    int c = 1;
    int d = 2;
    int f() const {
        return c + d;
    }
};

int main() {
    C c;
    cout << c.f() << endl;
    D a, b;
    D d = a;
    cout << d.f() << endl;   
}