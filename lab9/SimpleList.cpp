//
// Created by Bharat Kathi on 5/31/22.
//

#include "SimpleList.h"
#include <iostream>
#include <type_traits>

template<class T>
void destroy(T element) {
    // do nothing
}

template <class T>
void destroy(T* element) {
    // delete the pointer type
    delete element;
}

template<class T>
SimpleList<T>::SimpleList() {
    numElements = 0;
    elements = new T[CAPACITY];
}

template<class T>
SimpleList<T>::~SimpleList() {
    for (int i = 0; i < numElements; i++) {
        destroy(elements[i]);
    }
    delete[] elements;
}

template<class T>
T SimpleList<T>::at(int index) const {
    if (index >= numElements || index < 0) {
        throw InvalidIndexException();
    }
    return elements[index];
}

template<class T>
bool SimpleList<T>::empty() const {
    return numElements == 0;
}

template<class T>
T SimpleList<T>::first() const {
    if (numElements == 0) {
        throw EmptyListException();
    }
    return elements[0];
}

template<class T>
T SimpleList<T>::last() const {
    if (numElements == 0) {
        throw EmptyListException();
    }
    return elements[numElements -1];
}

template<class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template<class T>
void SimpleList<T>::insert(T item) {
    if (numElements == CAPACITY) {
        throw FullListException();
    }
    elements[numElements] = item;
    numElements++;
}

template<class T>
void SimpleList<T>::remove(int index) {
    if (numElements == 0) {
        throw EmptyListException();
    }
    else if (index >= numElements || index < 0) {
        throw InvalidIndexException();
    }
    destroy(elements[index]);
    for (int i = index + 1; i < numElements; i++) {
        elements[i-1] = elements[i];
    }
    numElements--;
}