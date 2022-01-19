

#include <iostream>
#include <typeinfo>


using std::endl;
using std::cout;
using std::cin;


template <typename T>
class myvector {
    private:
        T* ptr;
        int size;
        int capacity;
};