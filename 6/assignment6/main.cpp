#include <iostream>
#include <limits>
#include <ctime>
#include <vector>
#include "hm.hpp"

using namespace std;
typedef float T; // Change the type here


int main() {
    int x, r, round, i_th;

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

        vector<int> A;
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
        cout << "r=" << r << ", A[r]=" << A[r] << endl;

        /*
         * to do : Partition array by A[r]
         *         print the rearranged array
         */
        bz_partition(A, r);
        for (auto a:A) cout << a << ' ';
        cout << endl;
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

        vector<int> A;
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

        vector<int> A;
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
        cout << "i_th=" << i_th << ", value=" << r_select(A, i_th - 1) << endl;
    }

//
//    // Q4:
//    // clear the input buffer, no need to change.
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    cout << "--------------------------------- " << endl;
//    cout << " Q4: Test Dselect " << endl;
//    cout << "--------------------------------- " << endl;
//
//    cout << "How many times you want to test Dselect?" << endl;
//    cin >> round;
//    //input 0 to skip this part
//    for (int i = 0; i < round; ++i) {
//        // clear the input buffer, no need to change.
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        cout << "Input values: " << endl;
//        while (cin >> x) {
//            /*
//             *to do : store the inputs
//             */
//        }
//        // to do :
//        i_th = rand() % (n) + 1; // n is the size of current array
//
//        cout << "select i-th smallest element" << endl;
//        /*
//         *to do : deterministic selection
//         *        print i-th and i-th value
//         */
//    }

    return 0;
}
