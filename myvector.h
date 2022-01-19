
#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <typeinfo>


using std::endl;
using std::cout;
using std::cin;


template <typename T>
class myvector {
    private:
        T* ptr; // dynamically allocated c-like array...
        int size; // number of elements in array...
        int capacity; // total number of locations available... 
        
    public:
        myvector() {
            capacity = 4;
            ptr = new T[capacity];
            size = 0;
        }
};