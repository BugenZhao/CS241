//
// Created by Bugen Zhao on 2019/10/12.
//

#ifndef CS241_MYDATA_H
#define CS241_MYDATA_H

template<typename T>
struct myData {
    myData<T> *addr;
    T val;

    explicit myData(T val) : val(val), addr(this) {}

    myData() : addr(this) {};
};

template<typename T>
struct Cmp_by_val {
    bool operator()(myData<T> a, myData<T> b) {
        return a.val < b.val;
    }
};

template<typename T>
struct Cmp_by_addr {
    bool operator()(myData<T> a, myData<T> b) {
        return a.addr < b.addr;
    }
};

#endif //CS241_MYDATA_H
