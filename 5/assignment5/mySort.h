//
// Created by Bugen Zhao on 2019/10/12.
//

#ifndef CS241_MYSORT_H
#define CS241_MYSORT_H

template<typename Elem>
struct DefaultComparator {
    bool operator()(const Elem &a, const Elem &b) {
        return a < b;
    }
};

template<typename Iterator, typename Comparator>
Iterator partition(Iterator first, Iterator last, Comparator comp) {
    auto v = *first;
    --last;
    while (true) {
        while (first < last && comp(v, *last)) --last;
        if (first < last) *first = *last, ++first;
        while (first < last && comp(*first, v)) ++first;
        if (first < last) *last = *first, --last;
        if (first >= last) break;
    }
    *first = v;
    return first;
}

template<typename Iterator>
void mySort(Iterator first, Iterator last) {
    mySort(first, last, DefaultComparator<Iterator>());
}

template<typename Iterator, typename Comparator>
void mySort(Iterator first, Iterator last, Comparator comp) {
    if (last - first < 2) return;
    Iterator mid = partition(first, last, comp);
    mySort(first, mid, comp);
    mySort(mid + 1, last, comp);
}

#endif //CS241_MYSORT_H
