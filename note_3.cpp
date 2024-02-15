#include <iostream>

using namespace std;
void print() {
#ifndef NDEBUG
    cout << __func__ << endl;
#endif
    cout << "hello world" << endl;
}

void print2() {
#ifndef NDEBUG
    cout << __func__ << endl;
#endif
    cout << "hello world" << endl;
}

int main() {
    print(); print2();
    return 0;
}