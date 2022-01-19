
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

        class iterator {
            private:
                myvector* v; // the vector we are iterating over...
                int curIndex; // the element we are currently at...
            public:
                // default constructor...denotes the 1st item...
               iterator(myvector* v) {
                   this->v = v; //
                   curIndex = 0; //
               }
               // constructor...denotes the nth item...
               iterator(myvector* v, int n) {
                   this->v = v;
                   curIndex = n;
               }
               // advance to the next...
               iterator& operator++() {
                   curIndex++;
                   return *this;
               }
               // access current element...
               T& operator*() {
                   return v->ptr[curIndex];
               }
               // compare to stop iterating...
               bool operator != (const iterator& rhs) {
                   if (v != rhs.v) { // different vectors...
                       return true;
                   }
                   if (curIndex != rhs.curIndex) { // different index...
                       return true;
                   }
                    // same underlying vector and index, so iterator denotes same element...
                   return false
               }
        };
    public:
        myvector() {
            capacity = 4;
            ptr = new T[capacity];
            size = 0;
        }
};