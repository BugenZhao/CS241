#include <iostream>
#include <limits>
#include <ctime>
#include <vector>
#include <algorithm>
#include "hm.hpp"

using namespace std;
typedef int T; // Change the type here
constexpr bool DEBUG = true;


int main() {
    int r, round, i_th;
    T x;

    // Q1:
    cout << "--------------------------------- " << endl;
    cout << " Q1: Test Partition" << endl;
    cout << "--------------------------------- " << endl;

    cout << "How many times you want to test Partition?" << endl;
    cin >> round;
    // input 0 to skip this part
    for (int i = 0; i < round; ++i) {
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " << endl;

        vector<T> A;
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
            A.push_back(x);
        }

        int n = A.size();

        cout << "Partition array by random select pivot" << endl;
        // to do :
        r = rand() % (n); // n is the size of current array

        /*
         * to do ：print r and A[r];
         */
        T value = A[r];
        cout << "r=" << r << ", A[r]=" << value << endl;

        /*
         * to do : Partition array by A[r]
         *         print the rearranged array
         */
        int pos = bz_partition(A, r);
        for (auto a:A) cout << a << ' ';
        cout << endl;

        if (DEBUG) {
            auto test = [&A, value, n, pos]() {
                for (int j = 0; j < pos; ++j) {
                    if (A[j] > value) return false;
                }
                for (int j = pos; j < n; ++j) {
                    if (A[j] < value) return false;
                }
                return true;
            };
            assert(test());
            cout << "OK!" << endl;
        }
    }

    // Q2:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "--------------------------------- " << endl;
    cout << " Q2: Test Quicksort " << endl;
    cout << "--------------------------------- " << endl;

    cout << "How many times you want to test Quicksort?" << endl;
    cin >> round;
    // ----- input 0 to skip this part
    for (int i = 0; i < round; ++i) {
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " << endl;

        vector<T> A;
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
            A.push_back(x);
        }

        cout << "Sort Array" << endl;
        /*
         *to do : quicksort
         *        print the sorted array
         */

        quick_sort(A);
        for (auto a:A) cout << a << ' ';
        cout << endl;

        if (DEBUG) {
            vector<T> AA((A));
            sort(AA.begin(), AA.end());
            assert(AA == A);
            cout << "OK!" << endl;
        }
    }


    // Q3:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "--------------------------------- " << endl;
    cout << " Q3: Test Rselect " << endl;
    cout << "--------------------------------- " << endl;

    cout << "How many times you want to test Rselect?" << endl;
    cin >> round;
    //input 0 to skip this part
    for (int i = 0; i < round; ++i) {
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " << endl;

        vector<T> A;
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
            A.push_back(x);
        }
        int n = A.size();

        // to do:
        i_th = rand() % (n) + 1; // n is the size of current array
        cout << "select i-th smallest element" << endl;
        /*
         *to do : random selection
         *        print i-th and i-th value
         */
        auto value = r_select(A, i_th - 1);
        cout << "i_th=" << i_th << ", value=" << value << endl;

        if (DEBUG) {
            vector<T> AA((A));
            sort(AA.begin(), AA.end());
            assert(value == AA[i_th - 1]);
            cout << "OK!" << endl;
        }
    }


    // Q4:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "--------------------------------- " << endl;
    cout << " Q4: Test Dselect " << endl;
    cout << "--------------------------------- " << endl;

    cout << "How many times you want to test Dselect?" << endl;
    cin >> round;
    //input 0 to skip this part
    for (int i = 0; i < round; ++i) {
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " << endl;

        vector<T> A;
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
            A.push_back(x);
        }
        int n = A.size();

        // to do :
        i_th = rand() % (n) + 1; // n is the size of current array

        cout << "select i-th smallest element" << endl;
        /*
         *to do : deterministic selection
         *        print i-th and i-th value
         */
        auto value = d_select(A, i_th - 1);
        cout << "i_th=" << i_th << ", value=" << value << endl;

        if (DEBUG) {
            vector<T> AA((A));
            sort(AA.begin(), AA.end());
            assert(value == AA[i_th - 1]);
            cout << "OK!" << endl;
        }
    }

    return 0;
}
