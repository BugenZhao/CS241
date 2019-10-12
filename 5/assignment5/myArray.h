//
// Created by Bugen Zhao on 2019/10/12.
//

#ifndef CS241_MYARRAY_H
#define CS241_MYARRAY_H

#include <stdexcept>

namespace bz_array_exceptions {
    class IllegalIndex : public std::exception {
    };

    class IndexOutOfBound : public std::exception {
    };

    class IllegalIterators : public std::exception {
    };
}


template<typename Elem>
class myArray {
    Elem *array;
    unsigned N;
    unsigned C;

private:
    void resize(unsigned new_capacity);

public :
    class iterator {
        myArray *pMyArray;
        unsigned cur;
    public:
        iterator(myArray *arr, unsigned i) : pMyArray(arr), cur(i) {}

        Elem &operator*() {
            return (*pMyArray)[cur];
        }

        Elem *operator->() {
            return &(*pMyArray)[cur];
        }

        iterator &operator++() {
            cur = cur + 1;
            return *this;
        }

        iterator operator++(int) {
            auto ret = iterator(pMyArray, cur);
            cur = cur + 1;
            return ret;
        }

        iterator &operator--() {
            cur = cur - 1;
            return *this;
        }

        iterator operator--(int) {
            auto ret = iterator(pMyArray, cur);
            cur = cur - 1;
            return ret;
        }

        bool operator<(const iterator &rhs) const {
            if (pMyArray != rhs.pMyArray) throw bz_array_exceptions::IllegalIterators();
            return cur < rhs.cur;
        }

        bool operator>(const iterator &rhs) const {
            return rhs < *this;
        }

        bool operator<=(const iterator &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const iterator &rhs) const {
            return !(*this < rhs);
        }

        bool operator==(const iterator &that) {
            return pMyArray == that.pMyArray && cur == that.cur;
        }

        bool operator!=(const iterator &that) {
            return pMyArray != that.pMyArray || cur != that.cur;
        }

        int operator-(const iterator &rhs) {
            if (pMyArray != rhs.pMyArray) throw bz_array_exceptions::IllegalIterators();
            return (int) cur - (int) (rhs.cur);
        }

        iterator operator+(int i) {
            return iterator(pMyArray, cur + i);
        }
    }; // member type: iterator


    void push_back(const Elem &v); // insert v at end

    void pop_back(); // remove the last element

    iterator begin(); // iterator to first element

    iterator end();// iterator to one beyond last element

    int size() const; // the number of elements

    int capacity() const;

    Elem &operator[](int i) const;

    myArray<Elem> &operator=(const myArray &that);

    myArray();

    myArray(const myArray &that);

    virtual ~myArray();

    void clear();
};


template<typename Elem>
void myArray<Elem>::push_back(const Elem &v) {
    if (N == C) resize(2 * C);
    array[N] = v;
    ++N;
}

template<typename Elem>
void myArray<Elem>::pop_back() {
    if (N == 0) throw bz_array_exceptions::IllegalIndex();
    else --N;
    if (N <= C / 4) resize(C / 2);
}

template<typename Elem>
typename myArray<Elem>::iterator myArray<Elem>::begin() {
    return myArray<Elem>::iterator(this, 0);
}

template<typename Elem>
typename myArray<Elem>::iterator myArray<Elem>::end() {
    return myArray<Elem>::iterator(this, N);
}

template<typename Elem>
int myArray<Elem>::size() const {
    return N;
}

template<typename Elem>
int myArray<Elem>::capacity() const {
    return C;
}

template<typename Elem>
Elem &myArray<Elem>::operator[](const int i) const {
    if (i < 0) throw bz_array_exceptions::IllegalIndex();
    if (i >= N) throw bz_array_exceptions::IndexOutOfBound();
    else return array[i];
}

template<typename Elem>
myArray<Elem> &myArray<Elem>::operator=(const myArray &that) {
    clear();

    N = that.N;
    C = that.C;
    array = new Elem[C]{};
    for (int i = 0; i < N; ++i) {
        array[i] = that.array[i];
    }
}


template<typename Elem>
void myArray<Elem>::resize(unsigned new_capacity) {
    Elem *new_array = new Elem[new_capacity];
    unsigned n = (new_capacity < C) ? new_capacity : C;
    for (unsigned i = 0; i < n; ++i) {
        new_array[i] = array[i];
    }
    delete[] array;

    array = new_array;
    C = new_capacity;
}

template<typename Elem>
myArray<Elem>::myArray() {
    N = 0;
    C = 1;
    array = new Elem[C]{};
}

template<typename Elem>
myArray<Elem>::~myArray() {
    delete[] array;
}

template<typename Elem>
void myArray<Elem>::clear() {
    N = 0;
    C = 0;
    delete[]array;

    N = 0;
    C = 1;
    array = new Elem[C]{};
}

template<typename Elem>
myArray<Elem>::myArray(const myArray &that) {
    N = that.N;
    C = that.C;
    array = new Elem[C]{};
    for (int i = 0; i < N; ++i) {
        array[i] = that.array[i];
    }
}


#endif //CS241_MYARRAY_H
