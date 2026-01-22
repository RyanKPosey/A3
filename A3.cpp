/*
    Programmer: Ryan Posey
    Professor: Dr. Barnett
    Assignment: A3
    Purpose: Practice using pointers & classes
    Date: 1/21/2026
*/

#include <iostream>
using namespace std;

class Widget {
    // Init data members
    std::string _name;
    int _value;
    int* _data = nullptr;
    
    public:
    // Constructor
        Widget::Widget(std::string name, int value) : _name(name), _value(value), _data(new int[3]);

    // Destructor
        Widget::~Widget();
    
    // Print
        void print();

    // Setters
        void setData(int index, int value);

    // Getters
        int getData(int index);
};

Widget::Widget(std::string name, int value) : _name(name), _value(value), _data(new int[3]) {
    // Initialize _data values
    _data[0] = 4;
    _data[1] = 5;
    _data[2] = 6;
}

Widget::~Widget() {
    delete[] _data;
    _data = nullptr;
}

void Widget::print() {
    cout << "Widget Name: " << _name << endl;
    cout << "Widget Value: " << _value << endl;
    cout << "Address of Object: " << this << endl;
    cout << "Address of _data: " << static_cast<void*>(_data) << endl;
    cout << "3 Data Values: " << _data[0] << ", " << _data[1] << ", " << _data[2] << endl;
}

void Widget::setData(int index, int value) {
    if (index >= 0 && index < 3) {
        _data[index] = value;
    }
}

int Widget::getData(int index) {
    if (index >= 0 && index < 3) {
        return _data[index];
    }
    return -1; // Return an invalid value if index is out of bounds
}

int main() {
    // Create Widget instance
    Widget w1("alpha", 10);
    Widget* wp = &w1;

    // Call print method on both original instance and pointer
    w1.print();
    wp->print();

    Widget w2 = w1; // Shallow copy

    // Demonstrate that both instances share the same _data pointer address
    w1.print();
    w2.print();

    w1.setData(0, 100); // Modify w1's data

    // Print both instances to show that w2's data is also affected
    w1.print();
    w2.print();

    return 0;
}