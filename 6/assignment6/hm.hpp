//
// Created by Bugen Zhao on 2019/10/20.
//

#ifndef CS241_HM_HPP
#define CS241_HM_HPP

#include <vector>
#include <random>

using std::vector;

std::random_device rd;
std::mt19937 gen(rd());

template<typename T>
int bz_partition(vector<T> &A, int v_index, int lo, int hi) { // [lo,hi]
    T v = A[v_index];
    std::swap(A[lo], A[v_index]);
    while (true) {
        while (lo < hi && v < A[hi]) --hi;
        if (lo < hi) A[lo] = A[hi], ++lo;
        while (lo < hi && A[lo] < v) ++lo;
        if (lo < hi) A[hi] = A[lo], --hi;
        if (lo >= hi) break;
    }
    A[lo] = v;
    return lo;
}

template<typename T>
int bz_partition(vector<T> &A, int v_index = 0) {
    return bz_partition(A, v_index, 0, A.size() - 1);
}

template<typename T>
void quick_sort(vector<T> &A, int lo, int hi) {
    if (hi <= lo) return;
    int mid = bz_partition(A, hi, lo, hi);
    quick_sort(A, lo, mid - 1);
    quick_sort(A, mid + 1, hi);
}

template<typename T>
void quick_sort(vector<T> &A) {
    quick_sort(A, 0, A.size() - 1);
}

template<typename T>
T r_select(vector<T> &A, int i, int lo, int hi) {
    if (hi == lo) return A[lo];

    std::uniform_int_distribution<> dis(lo, hi);
    int v_index = dis(gen);
    T v = A[v_index];
    int j = bz_partition(A, v_index, lo, hi);
    if (j == i) return v;
    else if (j > i) return r_select(A, i, lo, j - 1);
    else return r_select(A, i, j + 1, hi);

}

template<typename T>
T r_select(vector<T> A, int i) {
    return r_select(A, i, 0, A.size() - 1);
}

#endif //CS241_HM_HPP
