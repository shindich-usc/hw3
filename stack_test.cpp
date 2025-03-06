#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;

int main() {
    Stack<int> s;
    cout << "Empty: " << boolalpha << s.empty() << endl;
    cout << "Pushing now..." << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Popping now.." << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << "Top: " << s.top() << endl;
    cout << "Empty: " << boolalpha << s.empty() << endl;
    return 0;
}