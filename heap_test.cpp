#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    Heap<int> h;
    cout << "Empty: " << boolalpha << h.empty() << endl;
    cout << "Pushing now..." << endl;
    h.push(6);
    cout << "Top: " << h.top() << endl;
    h.push(5);
    cout << "Top: " << h.top() << endl;
    h.push(3);
    cout << "Top: " << h.top() << endl;
    h.push(10);
    cout << "Top: " << h.top() << endl;
    h.push(1);
    cout << "Top: " << h.top() << endl;
    h.push(2);
    cout << "Top: " << h.top() << endl;
    cout << "Done pushing!" << endl;
    cout << "Popping now.." << endl;
    for (size_t i = 0; i < 6; i++) {
        h.pop();
        cout << "Top: " << h.top() << endl;
    }
    return 0;
}
