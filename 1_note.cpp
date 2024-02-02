#include <iostream>

using namespace std;

int main(void) {
    
    int num = 2;
    int&& a = static_cast<typename remove_reference<int>::type&&>(num);
    int &b = static_cast<typename remove_reference<int>::type&>(a);
    b = 1;
    cout << num << endl;

    int &&c = static_cast<typename remove_reference<int>::type&&> (b);
    c = 2;
    cout << num << endl;
    
    return 0;
}