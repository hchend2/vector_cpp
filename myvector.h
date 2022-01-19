
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
               iterator(myvector* vec) {
                   v = vec; //
                   curIndex = 0; //
               }
               // constructor...denotes the nth item...
               iterator(myvector* vec, int n) {
                   v = vec;
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
            ptr = new T[4]; //
            size = 0;
            capacity = 4;
        }

        // copy constructor...
        myvector(const myvector& other) {
            // allocate this vector same capacity as other...
            this->ptr = new T[other.capacity];
            this->size = other.size;
            this->capacity = other.capacity;
            // copy elements from other vector to this...
            for (int i = 0; i < other.size; i++) {
                this->ptr[i] = other.ptr[i];
            }
        }

        // move constructor...
        myvector(const myvector&& other) {
            this->ptr = other.ptr; //
            this->size = other.size; //
            this->capacity = other.capacity; //

            other.ptr = nullptr;
            other.size = 0;
            other.capacity;
        }
};