#include <iostream>
using namespace std;

int main() {
    const char * c_pointer = "hello";
    cout << c_pointer << endl;
    char * pointer = const_cast<char *> (c_pointer);
    *pointer = '1';// core dump
    cout << pointer << endl;
    return 0; 
}